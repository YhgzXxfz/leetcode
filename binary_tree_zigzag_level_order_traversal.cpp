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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (!root) return result;

		deque<TreeNode*> dq;
		dq.push_back(root);
		int d = -1;
		bool left_to_right = true;
		while (!dq.empty()) {
			int size = dq.size();
			result.push_back(vector<int>());
			++d;
			for (int i = 0; i < size; ++i) {
				if (left_to_right) {
					auto curr = dq.front();
					dq.pop_front();

					result[d].push_back(curr->val);
					if (curr->left) dq.push_back(curr->left);
					if (curr->right) dq.push_back(curr->right);
				} else {
					auto curr = dq.back();
					dq.pop_back();

					result[d].push_back(curr->val);
					if (curr->right) dq.push_front(curr->right);
					if (curr->left) dq.push_front(curr->left);
				}
			}
			left_to_right = !left_to_right;
		}
		return result;
	}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bfs(root, result, 1, true);
        return result;
    }

private:    
    void bfs(TreeNode* root, vector<vector<int>>& result, int level, bool lToR) {
        if (!root) return;
        
        if (level > result.size()) result.push_back(vector<int>());
        
        if (lToR) result[level-1].push_back(root->val);
        else result[level-1].insert(result[level-1].begin(), root->val);
        
        bfs(root->left, result, level+1, !lToR);
        bfs(root->right, result, level+1, !lToR);
    }
};
