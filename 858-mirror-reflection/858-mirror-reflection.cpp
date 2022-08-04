class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g = gcd(p,q);  //taking gcd because the value of p and q may have some common factors "MOST IMPO STEP"
        p=p/g;
        q=q/g;
        
        if(p==q)   //if both are equal then return 1 : as it would be 45degree when both have same value
            return 1;
        
        if(p%2==0)  //if p is even then return 2
        {
            return 2;
        }
        else  
        {
            if(q%2==0)  //if p is odd and q is even
                return 0;
            else   //if p is odd and q is also odd
                return 1;
        }
    }
};