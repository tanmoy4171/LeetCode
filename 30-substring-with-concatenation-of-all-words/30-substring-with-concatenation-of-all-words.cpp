class Solution {
public:
    vector<int> findSubstring(string str, vector<string>& words) {
        int len = words[0].length();
        
        unordered_map<string, int> contain;
        for(string s: words) contain[s]++;
        
        vector<int> res;
        for(int j = 0; j < len; j++) {
            unordered_map<string, int> found;
            int st = j;
            for(int i = 0 + j; i < str.size() - len + 1; i += len) {
                string curr = str.substr(i, len);
                if(contain.find(curr) != contain.end()) {
                    found[curr]++;
                    while(found[curr] > contain[curr]) {
                        found[str.substr(st, len)]--;
                        st += len;
                    }
                    int size = (i - st + len) / len;
                    if(size == words.size()) {
                        cout << j << " " << st << " " << i << endl;
                        res.push_back(st);
                    }
                } else {
                    found.clear();
                    st = i + len;
                }
            }
        }
        
        return res;
    }
};