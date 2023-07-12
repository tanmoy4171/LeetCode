class Solution {
public:
    bool dfs(int node,vector<int>&visited,vector<int>&path_visited,vector<vector<int>>& graph)
    {
        visited[node]=1;
        path_visited[node]=1;
        //if the current nodes have no adjacent nodes ie the node is a terminal node
        if(graph[node].size()==0)
        {
            //unvisit the node in the path visited and return
            path_visited[node]=0;
            return true;
        }
        //visit the adjacent nodes of i
        for(auto it:graph[node])
        {
            //if the node was not visited then go ahead and visit the node
            if(!visited[it] && !path_visited[it])
            {
                //if the dfs is return is returning true that means that it found a terminal node
                if(dfs(it,visited,path_visited,graph)==false)
                    return false;
            }
            //if the node is visited and path visited we have a cycle somewhere
            else if(visited[it] && path_visited[it])
                return false;
        }
        path_visited[node]=0;
        return true;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        //we need a visited and a path visited array
        vector<int>visited(n);
        vector<int>path_visited(n);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                dfs(i,visited,path_visited,graph);
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(!path_visited[i])
                ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};