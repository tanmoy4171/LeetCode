class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = k, a[26], m = INT_MIN, i = 0;
        memset(a, 0, sizeof(a));
        for (int j = 0; j < n; j++) {
            m = max(m, ++a[s[j] - 'A']);
            if (j - i - m == k) --a[s[i] - 'A'], ++i;
            ans = max(j - i + 1, ans);
        }
        return ans;
    }
};