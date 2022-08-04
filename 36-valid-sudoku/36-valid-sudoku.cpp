class Solution {
public:
    bool isValid(vector<vector<char>> &board,int row,int col){
        char ch=board[row][col];
        for(int i=0;i<9;i++){
            if(i!=row){
                if(board[i][col]==ch)
                    return false;
            }
        }
        for(int j=0;j<9;j++){
            if(j!=col){
                if(board[row][j]==ch)
                    return false;
            }
        }
        int k=(row/3)*3;
        int l=(col/3)*3;
        for(int i=k;i<k+3;i++){
            for(int j=l;j<l+3;j++){
                if(i!=row && j!=col){
                    if(board[i][j]==ch)
                        return false;
                }
            }
        }
        return true;
        
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(isValid(board,i,j)==false)
                        return false;
                }
            }
        }
        return true;
    }
};