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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return rec(root->left, root->right);
    }
    bool rec(TreeNode* l, TreeNode* r) {
        if(!l && !r) return true;
        if(!l || !r || l->val != r->val) return false;
        return rec(l->left, r->right) && rec(l->right, r->left);
    }
    
    
    bool isSymmetric_iter(TreeNode* root) {
        if(!root) return true;
        std::queue<TreeNode*> lq, rq;
        lq.push(root->left);
        rq.push(root->right);
        
        while(!lq.empty() && !rq.empty()) {
            TreeNode *l = lq.front(); lq.pop();
            TreeNode *r = rq.front(); rq.pop();
            if(!l && !r) continue;
            if(!l || !r || l->val != r->val) return false;
            lq.push(l->left);
            lq.push(l->right);
            rq.push(r->right);
            rq.push(r->left);
        }
        return true;
    }
};
