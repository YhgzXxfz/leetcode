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
    int minDiffInBST(TreeNode* root) {
        if (root->left) minDiffInBST(root->left);
        
        if (prev >= 0) result = min(result, root->val - prev);
        prev = root->val;
        
        if (root->right) minDiffInBST(root->right);
        return result;
    }
    
private:
    int result = INT_MAX, prev = -1;
};
