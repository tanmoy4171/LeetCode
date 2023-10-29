class Solution {
public:
int log_a_to_base_b(int a, int b)
{
    return log2(a) / log2(b);
}
    int poorPigs(int n, int Die, int Test) {
        if(n==1)return 0;
        int t = Test / Die; int ans =0 ;
        int x = log_a_to_base_b(n-1, t+1) +1 ;

       
        return x ;
        // return ceil((log2(n-1) +1)/ t);
    }
};