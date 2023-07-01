//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(int ind,int sum,vector<int> &num,vector<int> &ans,int n){
    	if(ind==n){
    		ans.push_back(sum);
    		return;
    	}
    	solve(ind+1,sum+num[ind],num,ans,n);
    	solve(ind+1,sum,num,ans,n);
    }
    vector<int> subsetSums(vector<int> num, int n)
    {
        vector<int>ans;
    	solve(0,0,num,ans,n);
    	sort(ans.begin(),ans.end());
    	return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends