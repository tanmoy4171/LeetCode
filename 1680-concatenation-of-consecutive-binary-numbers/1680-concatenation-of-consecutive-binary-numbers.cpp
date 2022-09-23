class Solution {
public:
    int concatenatedBinary(int n) {
        
        //start from n to 1
        long long ans=1;
        for(int i=2;i<=n;i++)
        {
            //calculate the bits in the current number (i)
            long long  num=(log(i)/log(2)) + 1;
            //left shift the bits as we need to append the i
            ans=ans<<num;
            ans|=i;
            ans%=1000000007;
        }
        return ans;
    }
};