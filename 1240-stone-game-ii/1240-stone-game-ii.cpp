class Solution {
public:
    #define ll long long
    ll dp[101][101];

    ll solve(vector<int>&piles,ll head,ll n,ll m){
        if(head>=n){
            return 0;
        }
        if(dp[head][m]!=-1){
            return dp[head][m];
        }
        ll answer=INT_MIN,sum=0;
        for(ll i=0;i<2*m;i++){
            if(head+i>=n){
                break;
            }
            sum+=piles[head+i];
            answer=max(answer,sum-solve(piles,head+i+1,n,max(m,i+1)));
        }
        return dp[head][m]=answer;
    }

    int stoneGameII(vector<int>& piles) {
        ll n=piles.size();memset(dp,-1,sizeof(dp));
        ll total=0;
        for(auto &x:piles){
            total+=x;
        }
        return (solve(piles,0,n,1)+total)>>1;
    }
};