//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfs(int vis[],int source , int par, vector<int > graph[]){
        vis[source] = 1;
        for (auto child : graph[source])
        {
            if(!vis[child]){
                if( dfs(vis, child,source ,graph)==true){
                    return true;
                }
            } 
            else if (child != par) return true;
        }
        return false;
    }
    public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        for(int i=0; i<V;i++){
            if(!vis[i]) {
                if(dfs(vis, i,-1,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends