class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<int> dp(m + 1, 0);
        for (int op = m - 1; op >= 0; op--) {
            int row[m + 1];
            for (int i = 0; i <= m; i++) { row[i] = dp[i]; }
            for (int left = op; left >= 0; left--) {
                dp[left] = max(multipliers[op] * nums[left] + row[left + 1], 
                               multipliers[op] * nums[n - 1 - (op - left)] + row[left]);
            }
        }
        return dp[0];
    }
};