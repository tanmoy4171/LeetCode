class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> ans(col, -1);
        for (int j = 0; j < col; j++)
        {
            int ballPosition = j;
            int i = 0;
            while (i < row)
            {
                if (grid[i][ballPosition] == 1)
                {
                    if (ballPosition + 1 == col) // WALL BLOCK CONDITION  Case IV
                    {
                        break;
                    }
                    else if (grid[i][ballPosition + 1] == -1) // ADJACENT COLUMN CONDITION  Case I
                    {
                        break;
                    }
                    ballPosition++; // ball moves to right
                }
                else
                {
                    if (ballPosition - 1 < 0) // WALL BLOCK CONDITION  Case III
                    {
                        break;
                    }
                    else if (grid[i][ballPosition - 1] == 1) // ADJACENT COLUMN CONDITION  Case II
                    {
                        break;
                    }
                    ballPosition--; // ball moves to left
                }
                i++;
            }
            if (i == row)
            {
                ans[j] = ballPosition;
            }
        }
        return ans;
    }
};