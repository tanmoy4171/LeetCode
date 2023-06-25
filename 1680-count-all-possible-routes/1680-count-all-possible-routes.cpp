class Solution {
public:
    int MOD = 1e9 + 7;
    int memo[101][201];
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(memo, -1, sizeof(memo));
        return dp(locations, start, finish, fuel);
    }
    int dp(vector<int>& A, int cur, int& f, int fuel){
        if(memo[cur][fuel] != -1)
            return memo[cur][fuel];
        int res = 0;
        for(int i = 0; i < A.size(); i++){
            if(i != cur && fuel >= abs(A[i] - A[cur]))
                res += dp(A, i, f, fuel - abs(A[i] - A[cur])) % MOD, res %= MOD;
            
        }
        return memo[cur][fuel] = res + (cur == f);
    }
};