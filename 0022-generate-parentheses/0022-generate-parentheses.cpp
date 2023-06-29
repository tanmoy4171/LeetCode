class Solution {
public:
    vector<string> ans;

    void Solve(int open,int close,string curr,int n)
    {
        if(curr.size()==2*n)
        {
            ans.push_back(curr);
            return;
        }
        if(open<n)
        {
            Solve(open+1,close,curr+"(",n);
        }
        if(close<open)
        {
            Solve(open,close+1,curr+")",n);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        Solve(0,0,"",n);
        return ans;
    }
};