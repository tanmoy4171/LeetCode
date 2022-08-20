class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2d vector for m*n and set value to 1;
		
        vector<vector<int>> dp(m, vector<int>(n, 1));
		
        // Many may confuse by seeing the above line 
        // This is same as dp[m][n] = {0} using array
        
        // iterate to all the grids in m*n and set dp[i][j] = dp[i-1][j] + dp[i][j-1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // Finally result the last grid ans
        return dp[m - 1][n - 1];
    }
};