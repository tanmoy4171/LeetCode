class Solution {
public:
    void DFS(int x, int y, vector<vector<int>> &image, int pc, int nc)  {

        if(x<0 || y<0 || x>=image.size() || y>=image[0].size() || image[x][y] !=pc)  
            return;
        image[x][y] = nc;
        
        DFS(x-1,y, image, pc, nc);
        DFS(x,y-1, image, pc, nc);
        DFS(x,y+1, image, pc, nc);
        DFS(x+1,y, image, pc, nc);
        
        return;
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int pColor = image[sr][sc];
        if(pColor == newColor)
            return image;
        
        DFS(sr,sc, image, pColor, newColor);
        return image;
        
        
    }
};