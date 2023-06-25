class Solution {    
public:
    int uniquePaths(int m, int n) {
        int formulaValue = m + n - 2;
        int run = min(m-1,n-1);
        
        // NcR formula
        
        double sum = 1;
        for(int i = 1; i <= run; i++){
            sum = sum * (formulaValue - run + i) / i;
        }
        
        return (int)sum;
        // int dp[m][n];
        // for(int i = 0; i < m; i++)
        //     for(int j = 0; j < n; j++)
        //         if(i == 0 || j == 0)
        //             dp[i][j] = 1;
        // for(int i = 1; i < m; i++)
        //     for(int j = 1; j < n; j++)
        //         dp[i][j] = dp[i-1][j] + dp[i][j-1];
        // return dp[m-1][n-1];
    }
};