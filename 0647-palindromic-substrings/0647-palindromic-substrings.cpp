class Solution {
public:
  int countSubstrings(string s) {
    int count = 0;
    for(int i = 0; i < s.size(); i++) {
      // odd
      int l = i, r = i;
      while(l >= 0 && r < s.size() && s[r] == s[l]) {
        count++; l--; r++;
      }
      // even
      l = i, r = i+1;
      while(l >= 0 && r < s.size() && s[r] == s[l]) {
        count++; l--; r++;
      }
    }
    return count;
  }
};