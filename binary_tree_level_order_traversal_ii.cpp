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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
		if (!root) return result;

		queue<TreeNode*> q;
		q.push(root);
		int d = -1;
		while (!q.empty()) {
			int size = q.size();
			result.push_back(vector<int>());
			++d;
			for (int i = 0; i < size; ++i) {
				auto curr = q.front();
				q.pop();

				result[d].push_back(curr->val);
				if (curr->left) q.push(curr->left);
				if (curr->right) q.push(curr->right);
			}
		}
        reverse(result.begin(), result.end());
		return result;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        bfs(root, result, 1);
        reverse(result.begin(), result.end());
        return result;
    }

private:    
    void bfs(TreeNode* root, vector<vector<int>>& result, int level) {
        if (!root) return;
        
        if (level > result.size()) result.push_back(vector<int>());
        
        result[level-1].push_back(root->val);
        bfs(root->left, result, level+1);
        bfs(root->right, result, level+1);
    }
};
