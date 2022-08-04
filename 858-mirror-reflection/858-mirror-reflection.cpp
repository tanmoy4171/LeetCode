class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(q==0)return 0;
        if(q==p)return 1;
        int k=1;
        int c=p;
       while(1)
       {
           if(c%q==0)break;
           else{
               k++;c=p*k;
           }
       }
        if((c/q)%2 and k%2==0)return 0;
        if((c/q)%2)return 1;
        else return 2;
    }
};