class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        initialize(row, col);
        auto isLand = vector(row, vector(col, false));
        const vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i = cells.size()-1; i>=0; i--){
            int x = cells[i][0]-1, y = cells[i][1]-1;
            isLand[x][y] = true;
            for(auto [dx, dy]:dirs){
                int i = x+dx, j=y+dy;
                if(i<0 || i>=row || j<0 ||j>=col || !isLand[i][j]) continue;
                join(key(x,y), key(i, j));
            }
            if(connect()) return i;
        }
        return -1;
    }

    void join(int i, int j){
        vroot[root(i)] = root(j);
    }

    int root(int i){
        if(vroot[i] == i) return i;
        return vroot[i] = root(vroot[i]);
    }

    bool connect() {
        return root(top) == root(bottom);
    }

    int key(int x, int y){
        return x*col+y;
    }

    void initialize(int row, int col){
        this->row = row;
        this->col = col;
        top = row * col;
        bottom = top+1;
        vroot.resize(row*col+2);
        for(int i=0;i<vroot.size();i++) vroot[i] = i;
        for(int j=0;j<col;j++) {
            join(key(0, j), top);
            join(key(row-1, j), bottom);
        }
    }

    int row;
    int col;
    int top;
    int bottom;
    vector<int> vroot;
};