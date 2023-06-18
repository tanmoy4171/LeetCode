class Solution {
public:
    
    int mod = 1e9+7;
    vector<int>dir = {-1,0,1,0,-1};
    int dfs(int i, int j, vector<vector<int>>&grid, int m, int n, vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = 1;
        for(int k=0;k<4;k++)
        {    
            int ni = i+dir[k];
            int nj = j+dir[k+1];
            if(ni>=0 and ni<m and nj>=0 and nj<n and grid[i][j] < grid[ni][nj]){
                ans = (ans%mod + dfs(ni, nj, grid, m, n, dp)%mod)%mod;
            }
        }
        return dp[i][j] = ans%mod;
    }
    
    int countPaths(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        long long ans=0;
        
        // start from every cell
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                ans = (ans%mod + dfs(i, j, grid, m, n, dp)%mod)%mod;
            }
        } 
        return ans; 
    }
};