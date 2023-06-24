class Solution {
public:
    int dp[31]={0};

    int fib(int n) {

        //handle invalid cases
        if(n<0)
            return 0;

        //base case 1: if reached 0 or 1-> n
        if(n==0 || n==1)
            return n;
        //base case 2: if the position reached before-> return its result immediately
        if(dp[n]!=0)
            return dp[n];

        //the current position will be the sum of the last two ones
        return dp[n]=fib(n-1)+fib(n-2);

    }
};