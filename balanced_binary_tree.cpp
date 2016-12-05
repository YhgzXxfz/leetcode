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
    bool isBalanced(TreeNode* root) {
        int height;
        return dfs(root, height);
    }
    
    bool dfs(TreeNode* root, int & height) {
        if (!root) {
            height = 0;
            return true;
        }
        
        int l_height, r_height;
        auto left = dfs(root->left, l_height);
        auto right = dfs(root->right, r_height);
        
        height = 1+max(l_height, r_height);
        if (left && right && abs(l_height -r_height) <= 1) return true;
        return false;
    }
};
