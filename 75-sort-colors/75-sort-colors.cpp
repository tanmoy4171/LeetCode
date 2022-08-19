class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = size(nums) - 1;
        for (int i = 0; i < size(nums) && i <= right; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left++]);
            } else if (nums[i] == 2) {
                swap(nums[i--], nums[right--]);
            }
        }
    }
};