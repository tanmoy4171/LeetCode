class Solution {
public:
    bool fun(vector<int>& p,int m,int h)
    {
        int ans=0;
        for(auto x: p)
        {
           ans+=(ceil(1.0*x/m));
            if(ans>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int res=-1;
       int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high)
        {
            int m=low+(high-low)/2;
            if(fun(piles,m,H)){res=m;high=m-1;}
            else low=m+1;
        }
        return res;
    }
};