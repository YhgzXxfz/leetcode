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
    int getMinimumDifference(TreeNode* root) {
        vector<int> inorder;
        dfs(root, inorder);
        int min_diff = INT_MAX;
        for (int i = 0; i < inorder.size()-1; ++i) {
            min_diff = min(min_diff, abs(inorder[i+1]-inorder[i]));
        }
        return min_diff;
    }

private:
    void dfs(TreeNode* root, vector<int>& inorder) {
        if (!root) return ;
        
        dfs(root->left, inorder);
        inorder.push_back(root->val);
        dfs(root->right, inorder);
    }
};
