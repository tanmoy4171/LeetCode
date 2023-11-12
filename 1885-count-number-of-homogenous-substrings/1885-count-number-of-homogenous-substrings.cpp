class Solution {
public:
    int countHomogenous(string s) {
        int i=0,j=0,n = s.length(),x,mod = 1e9+7;
        long long int ans = 0;
        while(i<n){
            j = i;
            while(j<n&&s[i]==s[j]){
                j++;
                x = (j-i);
                ans = (x+ans)%mod;
            }
            i = j;
        }
        return ans;
    }
};