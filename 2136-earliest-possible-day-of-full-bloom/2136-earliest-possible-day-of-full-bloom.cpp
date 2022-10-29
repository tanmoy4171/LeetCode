class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> v;
        for(int i=0;i<plantTime.size();i++)
        {
            v.push_back({growTime[i],plantTime[i]});
        }
        sort(v.begin(),v.end());// sort based on increasing growTime
        int time=0,res=0;
        for(int i=v.size()-1;i>=0;i--)// traverse from end to begin ( decreasing )
        {
            time+=v[i].second;
            res=max(res,time+v[i].first);
        }
        return res;
    }
};