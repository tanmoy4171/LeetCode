class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_set<int> s;
        vector<int> v;
        
        for(int i=0; i<nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(s.find(target-nums[i]) != s.end())
            {
                v.push_back(i+1);
                for(int j=0; j<nums.size(); j++)
                {
                    if(nums[j] == target-nums[i] && i != j)
                    {
                        v.push_back(j+1);
                        break;
                    }
                }
                if(v.size() == 2) break;
                else if(v.size() == 1)
                {
                    v.pop_back();
                }
            }
        }
        
        return v;
    }
};