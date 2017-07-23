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
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        
        int count = 0;
        dfs(root, count);
        return count;
    }

private:
    void dfs(TreeNode* node, int& count) {
        if (!node) return ;
        
        count += abs(sum(node->left) - sum(node->right));
        
        dfs(node->left, count);
        dfs(node->right, count);
    }
    
    int sum(TreeNode* node) {
        if (!node) return 0;
        
        return node->val + sum(node->left) + sum(node->right);
    }
};
