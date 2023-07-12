class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx = 0;
        //check what is the maximum index we can reach from that index...
        for (int maximum = 0; idx < nums.size() && idx <= maximum; ++idx)
            maximum = max(idx + nums[idx], maximum);       //if the maximum index reached is the last index of the array...
        return idx == nums.size();
    }
};