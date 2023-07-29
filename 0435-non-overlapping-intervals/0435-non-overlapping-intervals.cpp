class Solution {
public:
    static bool myComp(pair<int,int> a,pair<int,int> b)
    {
        return (a.second<b.second);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        vector<pair<int,int>> arr;
        for(auto it : intervals)
        {
            arr.push_back({it[0],it[1]});
        }
        sort(arr.begin(),arr.end(),myComp);
        int prev=0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[prev].second>arr[i].first){
                ans++;
            }
            else{
                prev=i;
            }
            
        }
        return ans;
    }
};