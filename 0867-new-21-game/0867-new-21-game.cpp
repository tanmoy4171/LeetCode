class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= (k + maxPts)) {
    	    return 1.0;
    	}
    	vector<double> dp(n + 1);
    	double res = 0.0;
    	double sum = 0.0;
    	for (int i = 1; i <= n; i++) {
    		dp[i] = i <= maxPts ? sum / maxPts + 1.0 / maxPts : sum/maxPts;
    		if (i < k) {
    		    sum += dp[i];
    		}
    		if (i > maxPts) {
    		    sum -= dp[i - maxPts];
    		}
    		if (i >= k) {
    		    res += dp[i];
    		}
    	}
    	return res;
    }
};