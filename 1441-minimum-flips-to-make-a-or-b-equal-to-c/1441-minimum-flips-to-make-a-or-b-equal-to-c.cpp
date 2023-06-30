class Solution {
public:
    int minFlips(int a, int b, int c) {
        long mask=(1L<<31);
        long y=(a|b);
        int cnt=0;
        for(int bit=31;bit>=0;bit--){
            if((mask & y)!=(mask & c)){
                if(mask & c){
                    cnt++;
                    cout<<cnt<<" ";
                }
                else {
                    if((mask & a)){
                        cnt++;
                    }
                    if((mask & b)){
                        cnt++;
                    }
                }
            }
            mask>>=1;
        }
        return cnt;
    }
};