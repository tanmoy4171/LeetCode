class Solution {
public:
    int dp[21][21];
    int solve(vector<int>& nums,int i,int j)
    {
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int t1=0;
        int t2=0;
        t1=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        t2=nums[j]+min(solve(nums,i,j-2),solve(nums,i+1,j-1));
        return dp[i][j]=max(t1,t2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum=accumulate(nums.begin(),nums.end(),0);
        int t1=solve(nums,0,nums.size()-1);
      //  cout<<t1<<endl;
        if(sum-t1>t1)return false;
        return true;
        
    }
};