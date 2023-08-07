class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int zeroct=0;
        int maxcnt=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0)zeroct++;
            else maxcnt*=nums[i];
        }
        vector<int> ans(n,0);
        if(zeroct>=2)return ans;
        else if(zeroct==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0)ans[i]=maxcnt;
            }
        }
        else{
            for(int i=0;i<n;i++){
                ans[i]=maxcnt/nums[i];
            }
        }
        return ans;
    }
};