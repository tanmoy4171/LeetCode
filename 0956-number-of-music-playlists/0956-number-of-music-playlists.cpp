typedef long long ll;

/* 
    Time: O(goal*n)
    Space: O(goal*n)
    Tag: DP (Memoization and Maths)
    Difficulty: H
*/

class Solution {
    vector<vector<int>> t;
    int mod = 1e9 + 7;

    ll solve(int goal, int used, int unused, int k) {
        if(goal<unused) return 0;
        if (goal == 0) {
            if (unused > 0) return 0;
            return 1;
        }
        if (t[goal][used] != -1) return t[goal][used];
        ll usingUsed=(max(0,used-k)>0?max(0, used - k) * solve(goal - 1, used, unused, k):0);
        ll usingNew=(unused>0?unused * solve(goal - 1, used + 1, unused - 1, k):0);
        t[goal][used] = (usingUsed + usingNew) % mod;
        return t[goal][used];
    }

public:
    int numMusicPlaylists(int n, int goal, int k) {
        t.resize(goal + 1, vector<int>(n + 1, -1));
        return solve(goal, 0, n, k);
    }
};