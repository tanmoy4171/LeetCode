class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n=colsum.size(),sum1=upper+lower,sum2=0;
        for(auto x:colsum){
            sum2+=x;
        }
        if(sum1!=sum2) return {};
        vector<int>vec1(n,0);
        vector<int>vec2(n,0);
        for(int i=0;i<n;i++){
            if(colsum[i]==2){
                if(upper&&lower){
                    vec1[i]+=1;
                    vec2[i]+=1;
                    upper--;
                    lower--;
                }
                else return {};
            }
        }
        int i=0;
        while(upper&&i<n){
            if(colsum[i]==1){
                vec1[i]+=1;
                upper--;
            }
            i++;
        }
        i=0;
        while(lower&&i<n){
            if(colsum[i]==1&&vec1[i]==0){
                vec2[i]+=1;
                lower--;
            }
            i++;
        }
        return {vec1,vec2};
    }
};
//    UPVOTE IF IT HELPS..THANK YOU