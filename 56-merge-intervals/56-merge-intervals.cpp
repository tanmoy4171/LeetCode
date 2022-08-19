class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>> res;
        if(intervals.size()==1)
        {
            res.push_back(intervals[0]);
            return res;
        }
        sort(intervals.begin(),intervals.end());
        if(intervals[1][0]<=intervals[0][1])
            res.push_back(vector<int>{intervals[0][0],max(intervals[1][1],intervals[0][1])});
        else
        {
            res.push_back(intervals[0]);
            res.push_back(intervals[1]);
        }
        for(int i=2;i<intervals.size();i++)
        {
            int n=res.size();
            if(intervals[i][0]<=res[n-1][1])
                res[n-1][1]=max(intervals[i][1],res[n-1][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};