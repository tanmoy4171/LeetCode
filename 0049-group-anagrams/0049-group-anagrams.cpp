class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> freq;
        for(auto a:strs){
            string b = a;
            sort(b.begin(), b.end());
            freq[b].push_back(a);
        }
        for(auto a:freq)
            ans.push_back(a.second);
        
        return ans;
    }
};