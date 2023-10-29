class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // support variables
        int res = -1, len = nums.size(), tot = 0;
        unordered_map<int, int> m;
        // storing the position of all the partial sums from left up to x
        // and relative indexes
        m[0] = -1;
        for (int i = 0; i < len && tot < x; i++) {
            m[tot += nums[i]] = i;
        }
        // edge case: x >= the sum of all the elements in the vector
        if (m[tot] == len - 1) return tot == x ? m[tot] + 1 : -1;
        // edge case: x found just summing left numbers
        if (tot == x) res = m[tot] + 1;
        // resetting tot
        tot = 0;
        // moving on from the right
        for (int j = len - 1; j >= 0 && tot < x; j--) {
            // updating res if there is a match
            if (m.find(x - (tot += nums[j])) != end(m)) {
                res = min(res > -1 ? res : len, m[x - tot] + 1 + len - j);
            }
        }
        return res;
    }
};