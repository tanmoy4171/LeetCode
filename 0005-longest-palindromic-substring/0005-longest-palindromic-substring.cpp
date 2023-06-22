class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int maxIdx = 0;
        int maxLen = 1;
        int i = 0;

        while (i < s.size()) {
            int start = i;
            int end = i;

            // expand the window from the end if it's an even palindrome
            while (end + 1 < s.size() && s[end] == s[end + 1]) { end++; }
            i = end + 1;

            // expand the window from both sides until it's not longer a palindrome
            while (start - 1 >= 0 && end + 1 < s.size() && s[start - 1] == s[end + 1]) {
                start--, end++;
            }

            int currLen = end - start + 1;
            if (currLen > maxLen) {
                maxIdx = start;
                maxLen = currLen;
            }
        }

        return s.substr(maxIdx, maxLen);
    }
};