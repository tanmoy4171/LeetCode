class Solution {
public:
        vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int k = nums.size();            // --> k is total number of lists
        
        /* ---------------------------------- Part 1 ------------------------------------ 
         
        create a single sorted vector containing numbers from all list  */
        
        vector<pair<int,int>> v;        // --> vector of pair {num, listID}
        
        for(int i=0; i<nums.size(); i++){
            
            for(int num : nums[i])
                v.push_back({num, i});
        }
        
        sort(v.begin(), v.end());
        
        /* ---------------------------------- Part 2 -------------------------------------
        
        find minimum window containing all listIDs  */
        
        int i=0, j=0;
        vector<int> freq (k, 0);
        
        int cnt = 0;
        int minRange = INT_MAX;
        vector<int> ans;
        
        while(j<v.size()){
            int id = v[j].second;
            
            freq[id]++;
            if(freq[id]==1) cnt++;
            
            while(cnt==k){
                
                if(v[j].first - v[i].first < minRange){
                    minRange = v[j].first - v[i].first;
                    ans = {v[i].first, v[j].first};
                }
                
                int idi = v[i].second;
                
                freq[idi]--;
                if(freq[idi]==0) cnt--;
                
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};