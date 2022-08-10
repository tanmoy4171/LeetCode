class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum =0,n=nums.size(), k = 0;
        for(int i:nums)sum+=i;
        if((sum - nums[0]) == 0) return 0;
        for(int i= 1; i<n;i++)
        {
            k+=nums[i-1];
            if(k == sum-(k+nums[i])) return i;
        }
        return -1;
    }
};