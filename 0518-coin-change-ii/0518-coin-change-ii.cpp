class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1,-1));
        int ans = helper(amount,0,coins,dp);
        return ans;
    }
    int helper(int amt, int i,vector<int>& coins,vector<vector<int>>& dp){
        if(amt==0)
            return 1;
        if(i==coins.size() || amt<0)
            return 0;
        if(dp[amt][i]!=-1)
            return dp[amt][i];
        int ans1 = helper(amt-coins[i],i,coins,dp);
        int ans2 = helper(amt,i+1,coins,dp);
        return dp[amt][i] = ans1+ans2;
    }
};