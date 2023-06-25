class Solution {
public:
    string removeTrailingZeros(string num) {
        // ===============================first method=============
        
        // int j = num.size() - 1;
        //  while (j >= 0 && num[j] == '0') {
        //     j--;
        // }
        // return num.substr(0, j + 1);
        
        
        // ===================second method============================ 
        return num.substr(0, num.find_last_not_of('0') + 1);
         
        
    }
};