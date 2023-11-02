class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int nrow = obstacleGrid.size(), ncol;
        if(nrow !=0)
            ncol = obstacleGrid[0].size();
        
        // only one element
        if(nrow==1 && ncol==1){
            if(obstacleGrid[0][0] ==1)
                return 0;
            else
                return 1;
        }
        // only one row
        else if(nrow==1 && ncol>1){
            for(int i=0;i<ncol;i++){
                if(obstacleGrid[0][i] == 1)
                    return 0;
            }
            return 1;
        }
        // only one column
        else if(ncol==1 && nrow>1){
            for(int i=0;i<nrow;i++){
                if(obstacleGrid[i][0] == 1)
                    return 0;
            }
            return 1;
        }
        
        vector<long> dp(nrow,1);
        
        // more than one row and one column
        for(int col = 0; col<ncol; col++){
            for(int row = 0; row<nrow; row++){
                // first column
                if(col ==0){
                    if(row==0 && obstacleGrid[row][0] ==1){
                        dp[row] = 0;
                    }
                    else if(row != 0 && (obstacleGrid[row][0] ==1 || obstacleGrid[row-1][0] ==1)){
                        dp[row] = 0;
                    }
                    else if(row !=0)
                        dp[row] = dp[row-1];
                }
                // first row
                else if(row ==0){
                    if(obstacleGrid[0][col] ==1 || obstacleGrid[0][col-1] ==1 || dp[0] == 0){
                        dp[0] = 0;
                        
                    }
                        
                    else
                        dp[0] = 1;
                    
                }
                
                else if(obstacleGrid[row][col] == 1){
                    dp[row] = 0;
                }
                else{
                    dp[row] += dp[row-1];
                    
                }
            }
            
        }
        return dp[nrow-1];
    }
};