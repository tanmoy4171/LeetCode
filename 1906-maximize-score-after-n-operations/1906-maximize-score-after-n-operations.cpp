class Solution {
    vector<int>dp;
    int gcd(int a,int b){
        if(b == 0)return a;
        return gcd(b, a % b);
    }
    int getMax(vector<int>&nums, int mask, int k){
        if(mask == 0)return 0;
        if(dp[mask] != -1)return dp[mask];
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int nmask = 1<<i | 1<<j;
                int temp = 0;
                if((mask & nmask) == nmask){
                    temp = k * gcd(nums[i],nums[j]) + getMax(nums, mask ^ nmask, k + 1);
                   }
                ans = max(ans, temp);
            }
        }
        return dp[mask] = ans;
    }
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int mask = pow(2, n)- 1;
        
        dp.resize(mask + 1, -1);
        return getMax(nums, mask, 1);
    }
};