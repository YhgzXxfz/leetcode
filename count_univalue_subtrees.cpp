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
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        
        int count = 0;
        helper(root, count);
        return count;
    }
    
private:
    bool helper(TreeNode* root, int& count) {
        if (!root) return true;
        
        auto left = helper(root->left, count);
        auto right = helper(root->right, count);
        
        if (left && right 
            && (!root->left || root->left->val == root->val) 
            && (!root->right || root->right->val == root->val)) {
            count++;
            return true;
        }
        return false;
    }
};
