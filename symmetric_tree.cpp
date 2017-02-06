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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        
        return isSymmetric(root->left, root->right);
    }
    
private:
    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (p && !q) return false;
        if (!p && q) return false;
        
        if (p->val != q->val) return false;
        
        auto outer = isSymmetric(p->left, q->right);
        auto inner = isSymmetric(p->right, q->left);
        
        return outer && inner;
    }
};
