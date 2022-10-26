class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++) {
            if(nums[i] == 0 && nums[i-1] == 0) return true;
        }
        for(int i=1;i<nums.size();i++) {
            nums[i] += nums[i-1];
            if(nums[i] % k ==0) return true;
            int j = i;
            while(j> 1 && nums[i] > k) {
                if((nums[i] - nums[j-2]) % k ==0) {
                    return true;
                }
                j--;
            }
        }
        return false;
    }
};