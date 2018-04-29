class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++) {
            for(int left=0; left<i; left++) {
                dp[i] += dp[left] * dp[i - left - 1];
            }
        }
        return dp[n];
    }
};
