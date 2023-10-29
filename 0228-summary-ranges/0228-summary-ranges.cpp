class Solution {
public:
    string converts(int start,int end)
    {
        if(start==end)
        {
            return to_string(start);
        }
        else
        {
            return to_string(start)+"->"+to_string(end);
        }
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> yes;
        int n=nums.size();
        if(n==0) return yes;
        int start=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1]+1)
            {
                yes.push_back(converts(start,nums[i-1]));
                start=nums[i];
            }
        }
        yes.push_back(converts(start,nums[n-1]));
        return yes;
    }
};