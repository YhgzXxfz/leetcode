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
    bool isValidBST(TreeNode* root) {
        cur_min = LLONG_MIN;
        return checkBST(root);
    }
    
private:
    bool checkBST(TreeNode* node){
        if (!node) return true;
        
        if (!checkBST(node->left)) return false;
        
        if (node->val <= cur_min) return false;
        cur_min = node->val;
        
        return checkBST(node->right);
    }
    
    long long cur_min;
};
