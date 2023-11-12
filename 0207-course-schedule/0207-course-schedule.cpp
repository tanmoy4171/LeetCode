class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<int> ans;

        for(auto x: pre){
            indegree[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int j: adj[node]){
                indegree[j]--;
                if(indegree[j] == 0) q.push(j);
            }
        }

        return ans.size() == n;
    }
};