class Solution {
public:
    int res=0;
    int closedIsland(vector<vector<int>>& grid) {
         if(grid.empty())
            return 0;
        int m = grid.size();
 		int n = grid[0].size();
		
		// Visited array 
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0||j==n-1||i==0||i==m-1) 
					// only the boundaries ones are to be chosen and send it to DFS.
                    dfs(grid,vis,i,j,m,n);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0 && !vis[i][j]){
					//  Only those who are zeroes and not visited till
                    dfs(grid,vis,i,j,m,n);
					// So after a complete spread of 0, then count 
                res++; // gives the closed number of islands
                }
            }
        }
        return res;
    }
     void dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis, int i, int j,int m,int n){
       // Base case
	   // If its out of bounds and already visited, so do nothing just return.
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==1||vis[i][j]){
            return ;
        }
		// make it as visited.
        vis[i][j]=true;
       
        // calling dfs in all the four directions. 
        dfs(grid,vis,i+1,j,m,n);
        dfs(grid,vis,i-1,j,m,n);
        dfs(grid,vis,i,j+1,m,n);
        dfs(grid,vis,i,j-1,m,n);
        
    }
};