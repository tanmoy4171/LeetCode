class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if(nums.size()%2!=0)
            return false;

        sort(nums.begin(),nums.end());
        int i=1;
        while(i<nums.size())
        {
            if(nums[i]!=nums[i-1])
                return false;
            i+=2;
        }
        return true;
    }
};