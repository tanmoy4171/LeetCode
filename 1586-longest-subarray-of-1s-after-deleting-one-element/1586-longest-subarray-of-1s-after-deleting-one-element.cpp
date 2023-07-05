class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,count=0,mx=0;
        bool flag=true;
        while(j<nums.size()){
            if(nums[j] == 0){
                flag = false;
                count++;
            }
                
            if(count < 1){
                j++;
            }else if(count == 1){
                mx = max(mx,(j-i+1));
                j++;
            }else{
                if(nums[i] == 0)
                    count--;
                i++;
                j++;
            }
        }
        if(flag)
            return nums.size()-1;
        return mx-1;
    }
};