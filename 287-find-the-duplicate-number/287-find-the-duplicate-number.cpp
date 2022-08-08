class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        bool arr[n];
        memset(arr,0,sizeof(arr));
        int ind=0;
        while(arr[ind]==0){
            arr[ind]=1;
            ind=nums[ind];
        }
        return ind;
    }
};