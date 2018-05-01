class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        init(grid);
        int x=0, y=0, ret = 0;
        while(findSeed(x, y)) {
            ret++;
            
            struct Pos{
                int x; int y;
                Pos(int xx, int yy) : x(xx), y(yy) {}
            };
            std::queue<Pos> q;
            q.push(Pos(x, y));
            while(!q.empty()) {
                Pos p = q.front(); q.pop();
                if(p.x<0 || p.x>=row || p.y<0 || p.y>=col || g[p.x][p.y]!='1') continue;
                g[p.x][p.y] = '2';
                q.push(Pos(p.x-1, p.y));
                q.push(Pos(p.x+1, p.y));
                q.push(Pos(p.x, p.y-1));
                q.push(Pos(p.x, p.y+1));
            }
        }
        return ret;
    }
    
    // Rec
    // 21ms
    int numIslandsRec(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        init(grid);
        int x=0, y=0, ret = 0;
        while(findSeed(x, y)) {
            ret++;
            rec(x, y);
        }
        return ret;
    }
    
    void rec(int x, int y) {
        if(x>=0 && x<row && y>=0 && y<col && g[x][y] == '1') {
            g[x][y] = '2';
            rec(x-1, y);
            rec(x+1, y);
            rec(x, y-1);
            rec(x, y+1);
        }
    }
    
    
private: // common for BFS/DFS
    bool findSeed(int& x, int& y) {
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(g[i][j] == '1') {
                    x = i;
                    y = j;
                    return true;
                }
            }
        }
        return false;
    }
        
private:
    void init(vector<vector<char>>& grid) {
        g = grid;
        row = g.size();
        col = g[0].size();
    }
    
    int row;
    int col;
    vector<vector<char>> g;
};

