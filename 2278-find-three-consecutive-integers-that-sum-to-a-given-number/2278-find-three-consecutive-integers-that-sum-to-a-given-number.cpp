class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> temp;
        if(num%3 != 0){
            
            return temp;
        }
        long long ans = num/3;
        temp.push_back(ans-1);
        temp.push_back(ans);
        temp.push_back(ans+1);
        return temp;
    }
};