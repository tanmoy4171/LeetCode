//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(int start, vector<int>adj[], vector<int>&col){
        for (auto i : adj[start]) {
            if (col[i] == -1) {
            col[i] = !col[start];
            if (!check(i, adj, col))return false;
            } 
            else if (col[i] == col[start])return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>col(V, -1);
	    for(int i=0; i<V; i++){
	        if(col[i]==-1){
	            if(!check(i, adj, col)) return 0;
	        }
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends