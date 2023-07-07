class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int cnt[26] = {}, res = -1;
        
        for(char ch: s)  cnt[ch - 'a']++;
        int st = -1, en = INT_MIN;
        for(int i = 0; i < 26; ++i){
            if(cnt[i] > 1){
                int j = 0;
                while( (j < s.size()) && (s[j] != i+'a')){
                    j++;
                }
                st = j;
                int k = s.size() - 1;
                while( ( k >= j) && (s[k] != i+'a')){
                    k--;
                }
                en = k;
            }
            res = max(res , en - st -1);
        }
       return res;
    }
};