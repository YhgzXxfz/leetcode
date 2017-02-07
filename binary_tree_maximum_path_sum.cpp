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
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        
        int max_sum = INT_MIN;
        maxPathSum(root, max_sum);
        return max_sum;
    }
    
private:
    int maxPathSum(TreeNode* root, int& max_sum) {
        if (!root) return 0;
        
        int left = max(0, maxPathSum(root->left, max_sum)), right = max(0, maxPathSum(root->right, max_sum));
        max_sum = max(max_sum, left + root->val + right);
        return root->val + max(left, right);
    }
};
