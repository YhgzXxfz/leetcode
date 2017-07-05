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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxLength(root, diameter);
        return diameter;
    }

private:
    int maxLength(TreeNode* root, int& diameter) {
        if (!root) return 0;
        
        int left = maxLength(root->left, diameter);
        int right = maxLength(root->right, diameter);
        
        diameter = max(diameter, left+right);
        return 1+ max(left, right);
    }
};
