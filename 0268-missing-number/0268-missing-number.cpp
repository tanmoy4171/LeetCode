class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0; 
        
        int total_sum = (n*(n+1))/2; // Sum of n natural numbers
        
        for (auto number : nums)  
            sum += number; // add the number to the sum
        
        return total_sum - sum; // missing no. is the diff of total_sum and sum
    }
};