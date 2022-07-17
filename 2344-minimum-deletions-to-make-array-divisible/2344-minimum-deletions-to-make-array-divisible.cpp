class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for (int i = 0; i < numsDivide.size(); i++)
        {
            g = __gcd(numsDivide[i], g);
        }
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (g % nums[i] == 0)
                return count;
            else
                count++;
        }
        return -1;
    }
};