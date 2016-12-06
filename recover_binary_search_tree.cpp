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
    TreeNode* first, *second, *last;
    
    void recoverTree(TreeNode* root) {
        if (!root) return ;
        
        first = second = last = nullptr;
        dfs(root);
        if (first && second) swap(first->val, second->val);
    }
    
    void dfs(TreeNode* root) {
        if (!root) return;
        
        dfs(root->left);
        if (last) {
            if (root->val < last->val) {
                if (!first) first = last;
                second = root;
            }
        }
        last = root;
        dfs(root->right);
    }
};
