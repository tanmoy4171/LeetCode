//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    //Function to return max value that can be put in knapsack of capacity W.
    
    int knapSack(int w, int weights[], int values[], int n) 
    { 
        vector<int> prev(w+1,0);
    	for(int i=weights[0];i<=w;i++)prev[i]=values[0];
    	for(int ind=1;ind<n;ind++){
    		for(int j=w;j>=0;j--){
    			int nottake=prev[j];
    			int take=-1e9;
    			if(weights[ind]<=j){
    				take=values[ind]+prev[j-weights[ind]];
    			}
    			prev[j]=max(take,nottake);
    		}
    	}
    	return prev[w];
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