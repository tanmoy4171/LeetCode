class Solution {
public:

    long long fun(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i==j)return nums[i];
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        long long l=nums[i]+min(fun(i+2,j,nums,dp),fun(i+1,j-1,nums,dp));
        long long r=nums[j]+min(fun(i+1,j-1,nums,dp),fun(i,j-2,nums,dp));
        
        return dp[i][j]=max(l,r);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        long long a=0,b=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        for(auto i:nums)
            b+=i;
        
        a=fun(0,n-1,nums,dp);
        long long c=b-a;
        return (a>=c);
    }
};