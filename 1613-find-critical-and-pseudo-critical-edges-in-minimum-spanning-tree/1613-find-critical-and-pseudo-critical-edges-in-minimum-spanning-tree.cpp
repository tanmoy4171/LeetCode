class DisjointSet{
private:
    vector<int> father, rank;
public:
    DisjointSet(int n): father(n), rank(n) {
        for(int i=0;i<n;i++) father[i]=i;
    }
    bool isRoot(int i) {return i==father[i]; };
    int getRoot(int i){
        if (isRoot(i)) return i;
        return father[i] = getRoot(father[i]);
    }
    bool inSameSet(int i, int j) { return (getRoot(i)==getRoot(j)); }
    void Union(int x, int y){
        int xRoot=getRoot(x);
        int yRoot=getRoot(y);
        int large, small;
        if (xRoot != yRoot) {
            if (rank[xRoot]<rank[yRoot]) {
                large = yRoot;
                small = xRoot;
            } else {
                large = xRoot;
                small = yRoot;
            }
            father[small] = large;
            if (rank[small]==rank[large]) rank[large]++;
        }
    }
};

class Solution {
private:
    vector<vector<int>> E;
    vector<vector<int>> edges;
    vector<bool> critical, noncritical;
    bool findequal;
    int tofind, weight;
    bool search(int u, int p) {
        if (u == tofind) return true;
        for (auto i : E[u]) {
            const auto& e = edges[i];
            int v = e[0] + e[1] - u;
            if (v == p) continue;
            if (search(v, u)) {
                if (e[2] == weight) {
                    critical[i] = false;
                    noncritical[i] = true;
                    findequal = true;
                }
                return true;
            }
        }
        return false;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        this->edges = edges;
        E.resize(n);
        
        int m = edges.size();
        vector<int> id(m);
        for(int i=0;i<m;i++) id[i] = i;
        sort(id.begin(), id.end(), [&edges](int a, int b) {return edges[a][2]<edges[b][2];});
        
        critical.resize(m);
        noncritical.resize(m);

        int lastw = -1;
        DisjointSet S(n);
        for (auto i:id) {
            int u = edges[i][0]; int v= edges[i][1]; auto w = edges[i][2];
            if (S.inSameSet(u,v)) {
                if (w!=lastw) continue;
                findequal=false;
                tofind =v; weight = w;
                search(u, -1);
                if (findequal) noncritical[i] = true;
            } else {
                S.Union(u,v);
                E[u].push_back(i);
                E[v].push_back(i);
                critical[i] = true;
                lastw = w;
            }
        }

        vector<int> C,NC;
        for (auto i=0; i<m; i++) 
            if (noncritical[i]) NC.push_back(i);
            else if (critical[i]) C.push_back(i);
        
        return {C, NC};
    }
};