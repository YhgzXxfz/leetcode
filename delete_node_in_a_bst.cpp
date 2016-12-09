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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            
            auto left_most = leftMost(root->right);
            root->val = left_most->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
    
private:
    TreeNode* leftMost(TreeNode* root) {
        if (!root) return nullptr;
        while (root->left) {
            root = root->left;
        }
        return root;
    }
};
