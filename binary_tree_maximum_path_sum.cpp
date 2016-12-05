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
        int maxSoFar = root->val;
        maxPathSum(root, maxSoFar);
        return maxSoFar;
    }
    
    int maxPathSum(TreeNode* root, int& maxSoFar) {
        if (!root) return 0;
        int left = maxPathSum(root->left, maxSoFar);
        int right = maxPathSum(root->right, maxSoFar);
        
        int m = root->val;
        int ret = max(m, max(left+m, right+m));
        
        maxSoFar = max(maxSoFar, max(ret, left+m+right));
        return ret;
    }
};
