class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;

        int l = 0; int r = height.size() - 1;
        int left_max = height[l]; int right_max = height[r];

        while (l < r) {
            if (left_max < right_max) {
                l++;
                left_max = max(left_max, height[l]);
                ans += max(0, left_max - height[l]);
            }
            else {
                r--;
                right_max = max(right_max, height[r]);
                ans += max(0, right_max - height[r]);
            }
        }
        return ans;
    }
};