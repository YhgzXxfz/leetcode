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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0, result = 0;
        solve(root, count, result, k);
        return result;
    }
    
    void solve(TreeNode* node, int& count, int& result, int k) {
        if (!node) return;
        
        solve(node->left, count, result, k);
        if (++count == k) {
            result = node->val;
            return;
        }
        
        solve(node->right, count, result, k);
    }
};
