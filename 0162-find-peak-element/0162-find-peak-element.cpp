class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) 
            if (nums[l] < nums[r]) ++l;
            else --r;
        return l;
    }
};