class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        auto sum=accumulate(nums.begin(),nums.end(),0); //O(N) complexity
        int lsum=0,rsum=sum;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            rsum-=nums[i];
            if(lsum==rsum)
                return i;
            lsum+=nums[i];
        }
        return -1;
    }
};