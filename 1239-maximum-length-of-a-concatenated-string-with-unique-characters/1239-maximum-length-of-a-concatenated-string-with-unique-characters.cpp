vector<int>v;
int n;
int ans;
void check(int ind,int cur)
{
    if(ind==n)
    {
        return ;
    }
    if((cur^v[ind])==(cur|v[ind]))
    {
        // cout<<"hi";
        ans = max(ans,__builtin_popcount(cur|v[ind]));
        check(ind+1,cur|v[ind]);
    }
    check(ind+1,cur);
}
class Solution {
public:
    int maxLength(vector<string>& arr) {
        v = {};
        ans = 0;
        for(int i=0;i<arr.size();i++)
        {
            int cur = 0;
            for(int j=0;j<arr[i].size();j++)
            {
                if((cur>>(arr[i][j]-'a'))&1)
                {
                    cur=0;
                    break;
                }
                else
                {
                    cur = cur|(1<<(arr[i][j]-'a'));
                }
            }
            if(cur)
            {
                // cout<<cur<<" ";
                v.push_back(cur);
            }
        }
        n = v.size();
        if(n==0)
        {
            return 0;
        }
        check(0,0);
        
        // cout<<"here"<<(133&131072);
        return ans;
    }
};