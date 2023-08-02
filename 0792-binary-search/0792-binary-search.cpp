class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int index = low + (high - low) / 2;
            if (nums[index] == target) return index;
            else if (nums[index] > target) high = index - 1;
            else low = index + 1;
        }
        
        return -1;
    }
};