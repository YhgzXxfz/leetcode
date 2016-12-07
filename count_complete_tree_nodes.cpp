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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int h = height(root), nodes = 0;
        while (root) {
            if (height(root->right) == h-1) {
                nodes += 1 << h;
                root = root->right;
            } else {
                nodes += 1 << (h-1);
                root = root->left;
            }
            h--;
        }
        return nodes;
    }
    
    int height(TreeNode* root) {
        return !root ? -1 : 1+height(root->left);
    }
};
