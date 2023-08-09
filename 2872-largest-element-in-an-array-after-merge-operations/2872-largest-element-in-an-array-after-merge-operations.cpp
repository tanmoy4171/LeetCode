class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long suffsum=0,ans=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>suffsum){
                suffsum=0;
            }
            suffsum+=nums[i];
            ans=max(ans,suffsum);
        }
        return ans;
    }
};