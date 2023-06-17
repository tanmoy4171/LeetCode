class Solution {
public:
    int minSteps(int n) {
        int res=0;
        while(n%2 == 0){
            res= res+2;
            n/=2;
        }
        int i=3;
        while(n!=1){
            if( n%i == 0){
                res = res+i;
                n/=i;
            }
             else i +=2;
        }
        return res;
    }
};