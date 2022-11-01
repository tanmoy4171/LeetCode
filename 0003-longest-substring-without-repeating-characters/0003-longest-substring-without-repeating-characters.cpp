class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if(str.size()==0)return 0;
        int l=0;
        int maxans=INT_MIN;
        unordered_set < int > set;
        for(int r=0;r<str.length();r++){
            if (set.find(str[r]) != set.end()) //if duplicate element is found
            {
              while (l < r && set.find(str[r]) != set.end()) {
                set.erase(str[l]);
                l++;
              }
            }
            set.insert(str[r]);
            maxans = max(maxans, r - l + 1);
        }
        return maxans;
    }
};