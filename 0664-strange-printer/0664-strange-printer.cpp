class Solution {
public:
    #define ll long long
    ll dp[101][101];
    ll solve(string &s,ll head,ll tail){
        if(head>tail){
            return 0;
        }
        if(dp[head][tail]!=-1){
            return dp[head][tail];
        }
        ll answer=INT_MAX;
        answer=min(answer,1+solve(s,head+1,tail));
        for(ll i=head+1;i<=tail;i++){
            if(s[head]==s[i]){
                answer=min(answer,solve(s,head+1,i-1)+solve(s,i,tail));
            }
        }
        return dp[head][tail]=answer;
    }

    int strangePrinter(string s) {
        ll n=s.length();
        memset(dp,-1,sizeof(dp));
        return solve(s,0,n-1);
    }
};