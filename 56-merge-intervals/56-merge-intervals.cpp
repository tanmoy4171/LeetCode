class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Optimal Solution Time O(NlogN) & Auxiliary Space O(1)
        int len=intervals.size();
        if(len<=1)
            return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res; // result vector
        // insert the first element into the result vector
        res.push_back(intervals[0]);
        for(int i=1;i<len;i++){
            if(res.back()[1]>=intervals[i][0])
                // back() points to the final element of the vector.
                // Update the endpoint of final element of result 
                // vector if there is an overlap with intervals[i]
                res.back()[1]=max(res.back()[1], intervals[i][1]);
            else
                // If no overlap, insert intervals[i]
                res.push_back(intervals[i]);
        }
        return res;
    }
};