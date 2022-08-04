class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // int l=0,r=nums.size()-1,mid,ans;
        // if(target>nums[r]){
        //     return r+1;
        // }
        // while(l<=r){
        //     mid=l+(r-1)/2;
        //     if(nums[mid]>=target){
        //         ans=mid;
        //         r=mid-1;
        //     }else{
        //         l=mid+1;
        //     }
        // }
        // return ans;
    }
};