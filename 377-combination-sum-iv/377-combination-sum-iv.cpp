class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // support variables
        long dp[target + 1];
        dp[0] = 1;
        // populating dp
        for (int i = 1; i <= target; i++) {
            // setting the initial value of a cell to 0
            dp[i] = 0;
            // updating dp[i] with all the previous combinations we can reach from there
            for (int n: nums) {
                if (i >= n) dp[i] += dp[i - n];
                if (dp[i] > INT_MAX) break;
            }
        }
        return dp[target];   
    }
};