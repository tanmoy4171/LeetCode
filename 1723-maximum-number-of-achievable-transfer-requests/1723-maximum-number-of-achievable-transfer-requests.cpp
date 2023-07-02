class Solution {
    int m;
    int dfs(int idx, vector<vector<int>>& requests, vector<int> &building, int n)
    {
        if(idx == m)
        {
            for(int i = 0; i < n; i++)
            {
                if(building[i] != 0)
                    return INT_MIN;
            }
            return 0;
        }
        int val1 = dfs(idx+1, requests, building, n);
        building[requests[idx][0]]--;
        building[requests[idx][1]]++;
        int val2 = 1 + dfs(idx+1, requests, building, n);
        building[requests[idx][0]]++;
        building[requests[idx][1]]--;
        return max(val1, val2);
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> building(n+1,0);
        m = requests.size();
        return dfs(0, requests, building, n);
    }
};