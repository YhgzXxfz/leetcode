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
    int sumNumbers(TreeNode* root) {
        int sum = 0, num = 0;
        compute(root, sum, num);
        return sum;
    }
    
    void compute(TreeNode* root, int& sum, int num) {
        if (!root) return ;
        num = num*10 + root->val;
        if (!root->left && !root->right) sum += num;
        
        compute(root->left, sum, num);
        compute(root->right, sum, num);
    }
};
