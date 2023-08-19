class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>res;
        
        unordered_map<int,int>mp;
        priority_queue<int>pq;
        int n=nums.size();
        

        
        for(int i=0;i<k;i++)
        {
           mp[nums[i]]++;
           pq.push(nums[i]);
        }
        
        res.push_back(pq.top());
        
        for(int i=k;i<n;i++)
        {
            mp[nums[i-k]]--;
            pq.push(nums[i]);
            mp[nums[i]]++;
            while(mp[pq.top()]==0)
                 pq.pop();
            
            res.push_back(pq.top());
        }
        return res;
    }
};