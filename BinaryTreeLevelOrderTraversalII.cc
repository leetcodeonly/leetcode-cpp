/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        if(!root) return ret;
        q.push(root);
        q.push(nullptr);
        
        vector<int> level;
        while(!q.empty()) {
            TreeNode *cur = q.front(); q.pop();
            if(!cur) {
                ret.push_back(level);
                level.clear();
                if(!q.empty()) q.push(nullptr);
                continue;
            }
            level.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
