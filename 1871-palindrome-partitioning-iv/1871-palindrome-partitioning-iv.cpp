class Solution {
public:

    bool checkPartitioning(string s) {
        int n=s.length();
         
         vector<bool>forward(n,false);
         vector<bool>backward(n,false);
         for(int i=0;i<n;i++){
             int k=1;
             while(i-k>=0 and i+k<n){
                 if(s[i-k]==s[i+k])k++;
                 else break;
             }
             if(i-k+1==0)forward[i+k-1]=true;
             if(i+k-1==n-1){
                 backward[i-k+1]=true;
             }
         }
         for(int i=0;i<n-1;i++){
             int j=i;
             int k=i+1;
             if(s[j]!=s[k])continue;
             while(j>=0 and k<n){
                 if(s[j]==s[k]){
                     j--;
                     k++;
                 }
                 else break;
             }
             if(j==-1){
               forward[k-1]=true;
             }
             if(k==n){
                 backward[j+1]=true;
             }
         }
       
        for(int i=0;i<n;i++){
             int k=0;
             while(i-k>=0 and i+k<n){
                 
                 if(s[i-k]==s[i+k]){
                    if(i-k-1>=0 and i+k+1<n and forward[i-k-1] and backward[i+k+1]){
                        return true;
                    }
                    k++;
                 }
                else break;
             }
            
         }
         for(int i=0;i<n-1;i++){
             int j=i;
             int k=i+1;
             if(s[j]!=s[k])continue;
             while(j>=0 and k<n){
                 if(s[j]==s[k]){
                     if(j-1>=0 and k+1<n and forward[j-1] and backward[k+1]){
                         return true;
                     }
                     j--;
                     k++;
                 }
                 else break;
             }
         }
         return false;
         
    }
};