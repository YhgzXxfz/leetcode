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
    void recoverTree(TreeNode* root) {
        if (!root) return ;
        
        first = second = last = nullptr;
        dfs(root);
        if (first && second) swap(first->val, second->val);
    }
   
private: 
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

    TreeNode* first, *second, *last;
};
