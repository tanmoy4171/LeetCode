class Solution {
public:
    void build_lps(string p,vector<int>& lps){
        lps[0]=0;
        int n=p.length();
        for(int i=1;i<n;i++){
            int j=lps[i-1];
            while(j>0 && p[i]!=p[j]){
                j=lps[j-1];
            }
            if(p[i]==p[j])j++;
            lps[i]=j;
        }
    }
    int strStr(string s, string p) {
        // Write your code here.
        int m=s.length(),n=p.length();
        vector<int> lps(n);
        build_lps(p,lps);
        int i=0,j=0;
        while(i<m){
            if(s[i]==p[j]){
                i++;
                j++;
                if(j==n){
                    return i-j;
                }
            }
            else if(i<m && s[i]!=p[j]){
                if(j>0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return -1;
    }
};