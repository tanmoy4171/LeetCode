//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool possible(int node,int n,int k,bool graph[101][101],int colour[] ){
        for(int i=0;i<n;i++){
            if(i!=node && graph[i][node]==1 && colour[i]==k)return false;
        }
        return true;
    }
    bool solve(int node,int n,int m,bool graph[101][101],int colour[] ){
        if(node==n)return true;
        for(int i=1;i<=m;i++){
            if(possible(node,n,i,graph,colour)){
                colour[node]=i;
                if(solve(node+1,n,m,graph,colour))return true;
                colour[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int colour[n]={0};
        if(solve(0,n,m,graph,colour))return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends