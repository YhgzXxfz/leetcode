/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// stack
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (!root) return result;

		stack<pair<TreeNode*, string>> s;
		s.push(make_pair(root, ""));
		while (!s.empty()) {
			auto curr = s.top();
			s.pop();
			auto node = curr.first;
			string path = curr.second;
			if (!node->left && !node->right) result.push_back(path+to_string(node->val));
			else {
				if (node->left) s.push(make_pair(node->left, path+to_string(node->val)+"->"));
				if (node->right) s.push(make_pair(node->right, path+to_string(node->val)+"->"));
			}
		}
		return result;
	}
};

// queue
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (!root) return result;

		queue<pair<TreeNode*, string>> q;
		q.push(make_pair(root, ""));
		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			auto node = curr.first;
			string path = curr.second;
			if (!node->left && !node->right) result.push_back(path+to_string(node->val));
			else {
				if (node->left) q.push(make_pair(node->left, path+to_string(node->val)+"->"));
				if (node->right) q.push(make_pair(node->right, path+to_string(node->val)+"->"));
			}
		}
		return result;
	}
};

// dfs
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path = "";
        dfs(root, result, path);
        return result;
    }

private:    
    void dfs(TreeNode* root, vector<string>& result, string path) {
        if (!root) return;
        
        string v = to_string(root->val);
        if (!root->left && !root->right) {
            result.push_back(path + v);
        }
        if (root->left) dfs(root->left, result, path+ v + "->");
        if (root->right) dfs(root->right, result, path+ v + "->");
    }
};
