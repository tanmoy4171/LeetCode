class Solution {
public:
    vector<vector<int>> dp;

    int f(int ind, int k,  vector<vector<int>>& events) {
        if(ind >= events.size() || k <= 0) return 0;
        if(dp[ind][k] != -1)return dp[ind][k];

        int nextInd = upper_bound(begin(events)+ind, end(events), events[ind][1], [](int t, const vector<int> &v){
                return v[0] > t;
            }) - begin(events);
        int pick = events[ind][2] + f(nextInd, k-1, events);
        int skip = f(ind+1, k, events);
        return dp[ind][k] = max(pick, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events), end(events));
        dp.resize(events.size(), vector<int>(k+1, -1));
        return f(0, k, events);
    }
};