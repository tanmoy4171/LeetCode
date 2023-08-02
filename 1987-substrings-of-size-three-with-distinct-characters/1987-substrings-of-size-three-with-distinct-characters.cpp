class Solution {
public:
    int countGoodSubstrings(string n) {
        int s=n.size();
        int a=0;
        for(int i=1;i<s-1;i++)
        {
            if(n[i]!=n[i-1]&&n[i]!=n[i+1]&&n[i-1]!=n[i+1])
            {
                a++;
            }
        }
        return a;
    }
};