class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int a = size - 3, b = size - 2, c = size - 1;

        while(a >= 0){
            if(nums[a] + nums[b] > nums[c]) return nums[a] + nums[b] + nums[c];
            else{
                a--;
                b--;
                c--;
            }
        }

        return 0;
    }
};