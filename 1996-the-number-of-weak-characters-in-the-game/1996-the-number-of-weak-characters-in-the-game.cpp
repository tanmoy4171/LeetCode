class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2)
    {
        return v1[0]==v2[0]?v1[1]>v2[1]:v1[0]<v2[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& nums)
    {
        int count=0;
        int n=nums.size();
        sort(nums.begin(),nums.end(),cmp);
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++)
        {
            while(s.size()&&s.top().first<nums[i][0]&&s.top().second<nums[i][1])
            {
                s.pop();
                count++;
            }
            s.push({nums[i][0],nums[i][1]});
        }
        return count;
    }
};