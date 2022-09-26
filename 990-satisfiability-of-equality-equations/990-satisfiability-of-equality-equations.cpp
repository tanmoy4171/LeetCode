class Solution {
public:
    int parent[26];
    int rank[26];
    
    void makeSet(){
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    int findPar(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findPar(parent[node]);
    }
    
    void uni(int u, int v){
        u=findPar(u);
        v=findPar(v);
        if(rank[u] < rank[v])
            parent[u]=v;
        else if(rank[v] < rank[u])
            parent[v]=u;
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    
    bool equationsPossible(vector<string>& eq) {
        // union find method
        makeSet();
        for(int i=0;i<eq.size();i++)
        {
            int var1=eq[i][0]-'a';
            int var2=eq[i][3]-'a';
            char op=eq[i][1];
            if(op=='=')
                uni(var1,var2);
        }
        
        // check
        for(int i=0;i<eq.size();i++)
        {
            int var1=eq[i][0]-'a';
            int var2=eq[i][3]-'a';
            char op=eq[i][1];
            if(op=='=')
            {
                if(findPar(var1) != findPar(var2))
                    return 0;
            }
            else
            {
                if(findPar(var1) == findPar(var2))
                    return 0;
            }
        }
        return 1;
    }
};