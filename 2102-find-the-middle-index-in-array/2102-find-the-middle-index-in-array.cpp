class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int s=nums.size();
        int j=0;
        while(j<s){
            int l=0,r=0;
            for(int i=0;i<s;++i){
                if(i<j){
                    l=l+nums[i];
                }
                else if(i>j)
                    r=r+nums[i];
            }
            if(l==r)
                return j;
            j++;
        }
        return -1;
    }
};