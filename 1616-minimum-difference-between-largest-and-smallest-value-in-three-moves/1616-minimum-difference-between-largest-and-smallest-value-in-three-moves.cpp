class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int n=nums.size();
        if(n<=4)return 0;
        ans=min(ans,nums[n-4]-nums[0]);
        ans=min(ans,nums[n-1]-nums[3]);
        ans=min(ans,nums[n-2]-nums[2]);
        ans=min(ans,nums[n-3]-nums[1]);
        return ans;
    }
};