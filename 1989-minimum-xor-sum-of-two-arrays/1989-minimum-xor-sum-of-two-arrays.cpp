class Solution {
private:
    vector<vector<int>>mem;
    int solve(vector<int>&nums1,vector<int>&nums2,int index,int config){
        if(index==nums1.size()){
            return 0;
        } else if(mem[index][config]!=-1){
            return mem[index][config];
        } else {
            int ans=INT_MAX;
            for(int i=0;i<nums2.size();i++){
                if((config>>i)&1){
                    continue;
                } else {
                    ans=min(ans,(nums1[index]^nums2[i])+solve(nums1,nums2,index+1,config^(1<<i)));
                }
            }
            return mem[index][config]=ans;
        }
    }
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        mem=vector<vector<int>>(n,vector<int>(1<<n,-1));
        return solve(nums1,nums2,0,0);
    }
};