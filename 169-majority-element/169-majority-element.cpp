class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;
        for(int it:nums){
            if(count==0) candidate=it;
            if(it==candidate) count++;
            else count--;
        }
        return candidate;
    }
};