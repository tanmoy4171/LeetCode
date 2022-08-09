class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length=nums.size();
        unordered_map<int,int> map;
        for(auto i=0;i<length;i++){
            if(map.find(target-nums[i])!=map.end()){
                return {i,map[target-nums[i]]};
        }
        map[nums[i]]=i;
        }
        return {};
    }
};