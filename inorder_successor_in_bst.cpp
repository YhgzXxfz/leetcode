/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// iterative
/*
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right) return leftMost(p->right);
        
        TreeNode* suc = nullptr;
        while (root) {
            if (p->val == root->val) break;
            else if (p->val < root->val) {
                suc = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return suc;
    }

private:
    TreeNode* leftMost(TreeNode* node) {
        if (!node) return nullptr;
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};
*/

// recursive
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return nullptr;
        
        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        } else {
            auto left = inorderSuccessor(root->left, p);
            return left ? left : root;
        }
    }
};
