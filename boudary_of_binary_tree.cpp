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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
		if (!root) return result;

		result.push_back(root->val);
		dfs(root->left, result, true, false);
		dfs(root->right, result, false, true);
		return result;
    }
    
private:
	void dfs(TreeNode* root, vector<int>& result, bool lb, bool rb) {
		if (!root) return ;

		if (lb) result.push_back(root->val);
		if (!lb && !rb && !root->left && !root->right) result.push_back(root->val);

		dfs(root->left, result, lb, rb && !root->right);
		dfs(root->right, result, lb && !root->left, rb);
		
		if (rb) result.push_back(root->val);
	}
};
