class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<int>> rset(9), cset(9), bset(9);
        assert(board.size() == 9 && board[0].size() == 9);
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char &ch = board[i][j];
                if(ch == '.') continue;
                int box = subbox(i, j);
                if(rset[i].find(ch) != rset[i].end()
                  || cset[j].find(ch) !=cset[j].end()
                  || bset[box].find(ch) != bset[box].end()) {
                    return false;
                }
                rset[i].insert(ch);
                cset[j].insert(ch);
                bset[box].insert(ch);
            }
        }
        return true;
    }
private:
    int subbox(int i, int j) {
        return (i / 3) * 3 + j / 3;
    }
};

