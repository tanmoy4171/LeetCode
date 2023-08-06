class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=arr.size()-1;i>-1;i--)
        {
            mp[arr[i]]=mp[arr[i]+difference]+1;
            ans = max(ans,mp[arr[i]]);
        }
        return ans;
    }
};