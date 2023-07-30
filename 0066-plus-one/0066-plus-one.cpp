class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1;
        while(i >= 0){
            if(digits[i]+1 == 10)
                digits[i] = 0;
            else{
                digits[i] = digits[i]+1;
                return digits;
            }
            i--;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};