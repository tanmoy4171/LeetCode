class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        long long nums1=nums[0],nums2=LLONG_MIN,count1=0,count2=0;
        for(long long it:nums){
            if(it==nums1)count1++;
            else if(it==nums2)count2++;
            else if(count1==0){
                nums1=it;
                count1=1;
            }else if(count2==0){
                nums2=it;
                count2=1;
            }else{
                count1--;
                count2--;
            }
        }
        count1=0;count2=0;
        for(long long it:nums){
            if(it==nums1)count1++;
            if(it==nums2)count2++;
        }
        vector<int> ans;
        if(count1>nums.size()/3)ans.push_back(nums1);
        if(count2>nums.size()/3)ans.push_back(nums2);
        return ans;
    }
};