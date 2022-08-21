class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return {};
            vector<int> mp_p(26), mp_s(26), res;
            for(char c : p) ++mp_p[c-'a'];
            for(int i = 0; i < p.length()-1; ++i) ++mp_s[s[i]-'a'];
            for(int i = 0, j = p.length()-1; j < s.length(); ++i, ++j)
            {
                ++mp_s[s[j]-'a'];
                if(mp_p == mp_s) res.push_back(i);
                --mp_s[s[i]-'a'];
            }
            return res;
    }
};