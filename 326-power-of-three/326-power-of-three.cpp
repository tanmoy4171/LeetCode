class Solution {
public:
    bool isPowerOfThree(int n) {
        return n < 1 ? false : !(1162261467 % n);
    }
};