class Solution {
public:
    int longestPalindrome(string s) {
        // res created, frequency array initialised and populated
        int res = 0;
        int f[52];
        for (auto &e: f) e = 0;
        for (auto c: s) f[c < 'a' ? c - 'A' : c - 'a' + 26]++;
        for (auto e: f) {
            // I take the frequence and round it down to the next multiple of 2
            res += e >> 1 << 1;
        }
        // if i did not use all the available characters, then the max lenght is + 1
        return res + (res != s.size());
    }
};