class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() <= 1 || board[0].size() <= 1) return;
        int x = 0, y = 0;
        while(findSeed(board, x, y)) {
            rec(board, x, y);
        }
        flip(board);
    }
private:
    bool findSeed(const vector<vector<char>>& board, int& x, int& y) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0; i<row; i++) {
            x = i;
            if(board[i][0] == 'O') {
                y = 0;
                return true;
            } else if(board[i][col-1] == 'O') {
                y = col - 1;
                return true;
            }
        }
        for(int j=0; j<col; j++) {
            y = j;
            if(board[0][j] == 'O') {
                x = 0;
                return true;
            } else if(board[row-1][j] == 'O') {
                x = row - 1;
                return true;
            }
        }
        return false;
    }
    
    void flip(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                board[i][j] = board[i][j] == 'A' ? 'O' : 'X';
            }
        }
    }
    
    void rec(vector<vector<char>>& board, int x, int y) {
        int row = board.size();
        int col = board[0].size();
        if(x>=0&& x<row && y>=0 && y<col && board[x][y] == 'O') {
            board[x][y] = 'A';
            rec(board, x-1, y);
            rec(board, x+1, y);
            rec(board, x, y-1);
            rec(board, x, y+1);
        }
    }
};
