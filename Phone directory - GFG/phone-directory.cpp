//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        int len = s.size();
        vector<vector<string>> sol;
        sol.reserve(len);
        for(int i=1; i<=len; i++)
        {
            string prefix = s.substr(0, i);
            int l = prefix.size();
            vector<string> req;
            req.reserve(n);
            for(int i=0; i<n; i++)
            {
                if(contact[i].size() >= l)
                {
                    if((contact[i].compare(0, l, prefix) == 0) && (find(req.begin(), req.end(), contact[i]) == req.end()))
                    {
                        req.push_back(contact[i]);
                    }
                }
            }
            if(req.size() != 0)
            {
                sort(req.begin(), req.end());
            }
            else
            {
                req.push_back("0");
            }
            sol.push_back(req);
        }
        return sol;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends