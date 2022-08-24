class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0 || n < 1) return false;
        for(int i = 0; i < n; i++)
        {
            long long int value = pow(3,i);
            if(value == n) return true;
            else if(value > n) return false;
        }
        return true;
    }
};