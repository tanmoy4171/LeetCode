class Solution {
public:
    void dfs(vector<vector<int>>& image,int sr,int sc,int newColor,int x)
	{
		if(sr<0 or sr>=image.size() or sc<0 or sc>=image[0].size() or image[sr][sc]!=x or image[sr][sc]==newColor)return;

		image[sr][sc]=newColor;
		dfs(image,sr-1,sc,newColor,x);
		 dfs(image,sr,sc+1,newColor,x);
		 dfs(image,sr+1,sc,newColor,x);
		 dfs(image,sr,sc-1,newColor,x);
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	int x=image[sr][sc];
	dfs(image,sr,sc,newColor,x);
	return image;
	}
};