class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& v) {
        
        vector<long long int>arr(v.size());
        int n = arr.size();
        
        for(int i=0;i<n;i++) arr[i] = v[i];
        
        long long int ans = 0 , MOD = pow(10,9) + 7;
        
        sort(arr.begin(),arr.end());
        set<long long int>s;
        
        for(int i=0;i<n;i++) s.insert(arr[i]);
        
        unordered_map<long long int,long long int>dp;
    
        for(int i=0;i<n;i++)
        {
            long long int ele = arr[i];
            
            //Calculate answer for arr[i] as a root.
            long long int cnt = 1;
            
            for(int j=0;j<i;j++)
            {
                long long int mul = arr[j]*arr[j];
                if(mul > ele) break;
                if(j > 0 && arr[j] == arr[j-1]) continue;
                long long int cc = ele/arr[j];
                
                if(ele%arr[j] == 0 && s.count(cc))
                {
                    if(arr[j] != cc) cnt = (cnt + 2*dp[arr[j]]*dp[cc])%MOD;
            
                    else cnt = (cnt + dp[arr[j]]*dp[cc])%MOD;
                }
            } 
            
            //store answer in dp for arr[i] as a root
            dp[ele] = cnt;
            ans = (ans + cnt)%MOD;
        }
        
        return ans;
    }
};