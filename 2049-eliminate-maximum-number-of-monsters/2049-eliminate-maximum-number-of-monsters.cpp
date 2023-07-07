class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time(dist.size());

        for(int i=0;i<dist.size();i++)
            time[i] = ceil((float)dist[i]/speed[i]);

        sort(time.begin(),time.end());

        int ans = 0;
        int T = 0;
        for(int i=0;i<time.size();i++)
        {
            if(T++<time[i])
                ans++;
            else
                break;
        }
        return ans;
    }
};