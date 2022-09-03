class Solution {
public:
    vector<int> ans;
      int n, k;
      void helper(int index, int number) {
          if(index >= n) {
              ans.push_back(number);
              return;
          }
          int i = 0;
          // since leading zeroes are not allowed
          if(index == 0) i = 1;
          for( ; i < 10; i++) {
          // checks for the required condition of absolute difference except for the first index as it can have any value
              if(index > 0 and abs(number % 10 - i) != k) continue;
              helper(index + 1, number * 10 + i);
          }
      }
      vector<int> numsSameConsecDiff(int N, int K) {
          if(N == 1) return {0,1,2,3,4,5,6,7,8,9};
          n = N, k = K;
          helper(0, 0);
          return ans;
      }
};