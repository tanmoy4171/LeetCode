//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    //Function to return max value that can be put in knapsack of capacity W.
    
    int f(int ind,int w,int values[], int weights[],vector<vector<int>> &dp){
    	if(ind==0){
    		if(weights[ind]<=w){
    			return values[0];
    		}
    		else return 0;
    	}
    	if(dp[ind][w]!=-1)return dp[ind][w];
    	int nottake=f(ind-1,w,values,weights,dp);
    	int take=-1e9;
    	if(weights[ind]<=w){
    		take=values[ind]+f(ind-1,w-weights[ind],values,weights,dp);
    	}
    	return dp[ind][w]=max(take,nottake);
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n, vector<int> (w + 1, -1));
	    return f(n-1,w,val,wt,dp);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends