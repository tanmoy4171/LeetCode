class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int x = pref[0], n = pref.size();
        for(int i = 1; i < n; i++) {
            pref[i] = x ^ pref[i];
            x ^= pref[i];
        }
        return pref;
    }
};