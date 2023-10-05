class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1);
        for(int i=n;i>=1;i--){
            long long solve=questions[i-1][0];
            if((i+1+questions[i-1][1])<dp.size()) solve+=dp[i+1+questions[i-1][1]];

            long long skip=0;
            if(i+1<dp.size()) skip+=dp[i+1];

            dp[i]=max(solve , skip);
        }
        return dp[1];
    }
};