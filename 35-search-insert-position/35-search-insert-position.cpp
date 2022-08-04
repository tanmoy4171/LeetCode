class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int n=nums.size();
    int s=0;
    int e=n-1;
    
    int mid=s+(e-s)/2;
    
while(s<=e)
    {
    
        if(nums[mid]<target)
            s=mid+1;
        
        else
        e=mid-1;
    
        mid=s+(e-s)/2;
    }
    
    return mid;
    }
};