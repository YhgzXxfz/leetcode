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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
    
    void dfs(TreeNode* node, vector<int>& result) {
        if (!node) return;
        dfs(node->left, result);
        result.push_back(node->val);
        dfs(node->right, result);
    }
};
