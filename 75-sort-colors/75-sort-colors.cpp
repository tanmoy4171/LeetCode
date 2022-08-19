class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_ptr = 0, one_ptr = 0, two_ptr = nums.size()-1;

        while (one_ptr <= two_ptr) {
            if (nums[one_ptr] == 0) swap(nums[zero_ptr++], nums[one_ptr++]);
            else if (nums[one_ptr] == 1) one_ptr++;
            else swap(nums[two_ptr--], nums[one_ptr]);
        }
    }
};