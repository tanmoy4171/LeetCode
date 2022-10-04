class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())return false;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]==target || matrix[i][m-1]==target)return true;
            else if(matrix[i][0]<=target<=matrix[i][m-1]){
                int lo=0,hi=m-1;
                while(lo<=hi){
                    int mid=(lo+hi)/2;
                    if(matrix[i][mid]==target)return true;
                    if(matrix[i][mid]<target)lo=mid+1;
                    else hi=mid-1;
                }
            }
        }
        return false;
    }
};