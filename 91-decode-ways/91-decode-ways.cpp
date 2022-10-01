class Solution {
public:
    int numDecodings(string s) {
        int dp[100] = {0};
        int n = s.size();
		for(int i=n-1; i>=0; i--){
            int a = stoi(s.substr(i,1));
            if(a >= 1 && a <= 9) dp[i] += (i+1<n?dp[i+1]:1);
            if(i<n-1){
                int b = stoi(s.substr(i,2));
                if(b >= 10 && b <= 26) dp[i] += (i+2<n?dp[i+2]:1);
            }
        }
		return dp[0];
    }
};