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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return rec(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
    TreeNode* rec(vector<int>::iterator preb, vector<int>::iterator pree,
                  vector<int>::iterator inb, vector<int>::iterator ine) {
        if(preb == pree) return nullptr;
        if(preb + 1 == pree) {
            assert(inb + 1 == ine);
            return new TreeNode(*preb);
        }
        auto root_it = std::find(inb, ine, *preb);
        TreeNode *root = new TreeNode(*preb);
        int left = std::distance(inb, root_it);
        root->left = rec(preb + 1, preb + left + 1, inb, inb + left);
        root->right = rec(preb + left + 1, pree, root_it + 1, ine);
        return root;
    }
};
