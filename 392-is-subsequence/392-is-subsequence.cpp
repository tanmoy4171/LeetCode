class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length())
            return false;
        if (s.empty() || t.empty())
            return true;
        int sidx = 0;
        for (int i = 0; i < t.length(); i++)
            if (t[i] == s[sidx] && ++sidx == s.length())
                return true;
        return false;
    }
};