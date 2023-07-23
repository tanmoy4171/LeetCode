//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int e,int f,vector<vector<int> > &dp ){
        
        if(f==0 || f==1)return f;
        if(e==1)return f;
        int mn=1e9;
        if(dp[e][f]!=-1)return dp[e][f];
        for(int k=1;k<=f;k++){
            int low=-1e9,high=-1e9;
            if(dp[e-1][k-1]!=-1){
                low=dp[e-1][k-1];
            }
            else{
                low=solve(e-1,k-1,dp);
                dp[e-1][k-1]=low;
            }
            if(dp[e][f-k]!=-1){
                high=dp[e][f-k];
            }
            else{
                high=solve(e,f-k,dp);
                dp[e][f-k]=high;
            }
            int temp=1+max(low,high);
            mn=min(temp,mn);
        }
        return dp[e][f] = mn;
    }
    int eggDrop(int e, int f) 
    {
        // your code here
        vector<vector<int> > dp (e+1,vector<int> (f+1,-1));
        return solve(e,f,dp);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends