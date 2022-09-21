class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int size = queries.size();
        int sum = 0;
        vector<int> answer;
        
        for(int num : nums)
            if(num % 2 == 0)
                sum += num;
        
        for(int i = 0; i < size; i++){
            int val = queries[i][0], index = queries[i][1];
            int valToPush = sum;
            if(nums[index] % 2 == 0)
                valToPush -= nums[index];
            nums[index] += val;
            if(nums[index] % 2 == 0)
                valToPush += nums[index];
            sum = valToPush;
            answer.push_back(valToPush);
        }
        
        return answer;
    }
};