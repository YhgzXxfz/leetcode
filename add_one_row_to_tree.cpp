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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            auto node = new TreeNode(v);
            node->left = root;
            return node;
        } else if (d == 0) {
            auto node = new TreeNode(v);
            node->right = root;
            return node;
        }
        
        if (!root) return nullptr;
        else if (d == 2) {
            root->left = addOneRow(root->left, v, 1);
            root->right = addOneRow(root->right, v, 0);
        } else {
            root->left = addOneRow(root->left, v, d-1);
            root->right = addOneRow(root->right, v, d-1);
        }
        return root;
    }
};
