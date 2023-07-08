class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        int n = w.size();
        if (k==1||n==k){ 
            return 0;
        }
        vector<int> v;
        for (int i = 0; i < n-1; i++)
        {
            v.push_back(w[i] + w[i+1]);
        }
        sort(v.begin(), v.end());
        long long mini = 0;
        long long maxi = 0;
        for (int i = 0; i < k-1; i++)
        {
            mini += v[i];
            maxi += v[n-2-i];
        }
        return maxi - mini;
    }
};