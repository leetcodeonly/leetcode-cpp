class Solution {
public:
    // Recursive
    // 3ms
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> out;
        std::string path;
        rec(n, n, path, out);
        return out;
    }
private:
    void rec(int left, int right, std::string& path, std::vector<std::string>& out) {
        if(left > right || left < 0 || right <0) return;
        if(left == 0 && right == 0) {
            out.push_back(path);
            return;
        }
        
        path.push_back('(');
        rec(left - 1, right, path, out);
        path[path.size() - 1] = ')';
        rec(left, right - 1, path, out);
        path.pop_back(); // backtrack
    }
    
    // Iterator
    // 4ms
    vector<string> generateParenthesisIt(int n) {
        std::vector<std::vector<std::string>> dp(1 + n);
        dp[0].push_back(std::string(""));
        for(int j=1; j<n+1; j++) {
            dp[j].push_back(std::string(j, '('));
        }
        for(int i=1; i<n+1; i++) {
            for(int j=i; j<n+1; j++) {
                for(auto it=dp[j].begin(); it!=dp[j].end(); it++) {
                   it->push_back(')');
                }
                if(j!=i) {
                    for(auto it=dp[j-1].begin(); it!=dp[j-1].end(); it++) {
                        dp[j].push_back(*it + "(");
                    }
                }
            }
        }
        return dp[n];        
    }
};

