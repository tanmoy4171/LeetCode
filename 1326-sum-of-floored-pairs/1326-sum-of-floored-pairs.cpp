#define ll long long int
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
         ll mx = 1e5;
         vector<ll>sieve(mx+2,0),prefix(mx+2,0);
         for(auto i :  nums)
            sieve[i]++;
        for(ll i=1;i<=mx;i++){
            prefix[i] = prefix[i-1]+sieve[i];
        }
        ll ans = 0;
        ll mod = 1e9+7;
        for(ll i=1;i<=mx;i++){
            ll count =1;
            for(ll j=i;j<=mx;j+=i){
                ll start = j;
                ll end = j+i-1;
                end = min(mx,end);
                ll sum  = ((prefix[end]-prefix[start-1])*count)%mod;
                sum = (sum*sieve[i])%mod;
                ans+=sum;
                ans%=mod;
                count++;
            }
        }
        return ans;
    }
};