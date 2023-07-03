class Solution {
public:
    bool buddyStrings(string s, string g) {
        int n1=s.size(),n2=g.size();
        if(n1 != n2 || n1==1) {
            return 0;
        }
        int j=0;
        set<int> st(s.begin(),s.end());
        if(s == g && st.size()<s.size()) {
            return true;
        }
        vector<int> v;
        for(int i=0;i<n1;i++)
        {
            if(s[i] != g[i]) {
                v.push_back(i);
            }
        }
        return v.size()==2 && s[v[0]]==g[v[1]] && s[v[1]]==g[v[0]];
    }
};