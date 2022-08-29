class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<char>>&grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j]==1 || grid[i][j]!='1')
            return ;
        vis[i][j]=1;
        dfs(i+1,j,vis,grid);
        dfs(i-1,j,vis,grid);
        dfs(i,j+1,vis,grid);
        dfs(i,j-1,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='1')
                {
                    dfs(i,j,vis,grid);
                    c++;
                }
            }
        }
        return c;
    }
};