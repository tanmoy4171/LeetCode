class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        
        for(int i = 1; i <= n; i++){
            bool divisible3 = i % 3; 
            bool divisible5 = i % 5;
            
            //if divisible by both 3 & 5
            if( !divisible3 && !divisible5){
                ans.push_back("FizzBuzz");
            }
            //if divisible by 3
            else if( !divisible3 ){
                ans.push_back("Fizz");
            }
            //if divisible by 5 
            else if( !divisible5 ){
                ans.push_back("Buzz");
            }
            else{
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};