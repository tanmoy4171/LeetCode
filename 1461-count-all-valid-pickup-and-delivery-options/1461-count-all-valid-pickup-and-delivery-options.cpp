class Solution {
public:
    int mod=1e9+7;
    int countOrders(int n) {
        int places = 2*n;
        long long ans=1;
        while(places>=2)
        {
            ans=((ans%mod)*((places*(places-1)/2)%mod))%mod;    
            places-=2;
        }
        return (int)ans;
    }
};