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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }

private:    
    void dfs(TreeNode* root, int level, vector<int>& result) {
        if (!root) return;
        
	if (level >= result.size()) result.push_back(root->val);
        dfs(root->right, level+1, result);
        dfs(root->left, level+1, result);
    }
};
