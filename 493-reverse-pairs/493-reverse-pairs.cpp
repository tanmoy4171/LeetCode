class Solution {
private:
    int merge(vector<int>& nums, int low, int mid, int high){
        int count = 0;
        int j = mid + 1;
        for(int i=low;i<mid+1;i++){
            while(j<=high and nums[i]>(2LL*nums[j])){
                j++;
            }
            count += j - (mid+1);
        }
        
        vector<int> temp;
        int s = low, e = mid+1;
        while(s<=mid and e<=high){
            if(nums[s]<nums[e]) temp.push_back(nums[s++]);
            else temp.push_back(nums[e++]);
        }
        while(s<=mid) temp.push_back(nums[s++]);
        while(e<=high) temp.push_back(nums[e++]);
        
        int k=0;
        for(int i=low;i<=high;i++){
            nums[i] = temp[k++];
        }
        return count;
    }
    
    int mergeSort(vector<int>& nums, int low, int high){
        if(low>=high) return 0;
        int mid = low + (high-low)/2;
        int inv = mergeSort(nums, low, mid);
        inv += mergeSort(nums, mid+1, high);
        inv += merge(nums, low, mid, high);
        return inv;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};