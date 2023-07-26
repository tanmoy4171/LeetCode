class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max_len=min(rectangles[0][0],rectangles[0][1]),cnt=1;
        for(int i=1;i<rectangles.size();i++){
            int min_len= min(rectangles[i][0],rectangles[i][1]);
            if(min_len==max_len){
                cnt++;
            }else if(min_len>max_len){
                max_len=min_len;
                cnt=1;
            }
        }
        return cnt;

        
    }
};