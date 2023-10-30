class Solution {
    using minheap = priority_queue<string,vector<string>,greater<string>>;
private:
    unordered_map<string,minheap> m;
    vector<string> ans;
    void hierholzer(string s) {
        while (!m[s].empty()) {
            string temp = m[s].top();
            m[s].pop();
            hierholzer(temp);
        }
        ans.push_back(s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& s : tickets) m[s[0]].push(s[1]);
        hierholzer("JFK");
        return vector<string>(rbegin(ans), rend(ans));
    }
};