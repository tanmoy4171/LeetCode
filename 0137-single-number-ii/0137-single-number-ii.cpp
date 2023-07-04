class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);
        
        for(int i = 0; i < nums.size(); ++i)
        {
            long long int n = abs(nums[i]);      // number can be large so to avoid overflow take long long int. Also the taken integer can be negative so to avoid ambiguity and complexity of code take absolute value of the number
            int j = 0;
            while(n)
            {
                if((n & 1) == 1)
                    ++bits[j];
                
                ++j;
                n >>= 1;
            }
        }
        
        for(int i = 0; i < bits.size(); ++i)
        {
            if((bits[i] % 3) == 0)
                bits[i] = 0;
            else
                bits[i] = 1;
        }
        
        long long int res = 0;     // result can be large so to avoid overflow take long long int
        
        for(int i = 0; i < bits.size(); ++i)
        {
            if(bits[i] == 1)
                res += (1 * pow(2, i));
            else
                continue;
        }
        
		//since our result can be negative or positive. We have solved the problem for positive consideration. But it can be possible that our result may be present both in positive and negative form
		// example: [-2,-2,1,1,4,1,4,4,-4,-2]
		//So the below lines will help us to give our final result
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(res == nums[i])
                ++count;
        }
        
        return (count == 1 ? res : (-res));
    }
};