//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    map<int,pair<int,int>> m;
		    string ans = "";
		    for(int i=0;i<s.length();i++){
		        int res = s.length();
		        int c = m[s[i]].first;
		        m[s[i]] = {c+1,i};
		        for(auto it:m){
		            if(it.second.first == 1){
		                res = min(res,it.second.second);
		            }
		        }
		        if(res!=s.length())ans.push_back(s[res]);
		        else ans.push_back('#');
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends