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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        
        int first = INT_MAX, second = INT_MAX;
        dfs(root, first, second);
        return second == INT_MAX ? -1 : second;
    }
    
private:
    void dfs(TreeNode* root, int& first, int& second) {
        if (!root) return ;
        
        if (root->val < first) {
            second = first;
            first = root->val;
        } else if (root->val > first && root->val < second) {
            second = root->val;
        }
        
        dfs(root->left, first, second);
        dfs(root->right, first, second);
    }
};
