class Solution {
public:
    bool isPowerOfFour(int n) {
       // return num > 0 && (num & (num - 1)) == 0 && (num & 0xAAAAAAAA) == 0;
        if(n ==  1){
            return true;
        }
        if(n == 0){
            return false;
        }
        if(n % 4 != 0){
            return false;
        } 
        
        return isPowerOfFour(n/4);
    }
};