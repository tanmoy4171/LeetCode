class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0;
        int right = n-k;
        
        // we want starting point -> place left to it's correct index
        while(left<right){
            int mid = left + (right - left)/2;
            if(x - arr[mid] <= arr[mid+k] - x){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return vector<int>(arr.begin()+left,arr.begin()+left+k);
    }
};