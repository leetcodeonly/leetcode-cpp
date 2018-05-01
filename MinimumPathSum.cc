class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        assert(grid.size() >= 1 && grid[0].size() >= 1);
        int row = grid.size();
        int col = grid[0].size();
        std::vector<std::vector<int>> dp(grid);
        for(int i=1; i<row; i++) {
            dp[i][0] += dp[i-1][0];
        }
        for(int j=1; j<col; j++) {
            dp[0][j] += dp[0][j-1];
        }
        for(int i=1; i<row; i++) {
            for(int j=1; j<col; j++) {
                dp[i][j] += std::min<int>(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[row-1][col-1];
    }
};

