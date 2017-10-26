/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// iterative
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
		vector<TreeNode*> s;
		int total = 0;
		TreeNode* curr = root, *prev = nullptr;
		while (curr || !s.empty()) {
			while (curr) {
				s.push_back(curr);
				total += curr->val;
				curr = curr->left;
			}
			curr = s.back();
			if (!curr->left && !curr->right && total == sum) {
				vector<int> temp;
				for (auto node : s) {
					temp.push_back(node->val);
				}
				result.push_back(temp);
			}

			if (curr->right && curr->right != prev) {
				curr = curr->right;
			} else {
				prev = curr;
				total -= curr->val;
				s.pop_back();
				curr = nullptr;
			}
		}
		return result;
    }
};


// dfs
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> solution;
        dfs(root, result, solution, sum);
        return result;
    }
    
    void dfs(TreeNode* root, vector<vector<int>>& result, vector<int>& solution, int sum) {
        if (!root) return;
        
        sum -= root->val;
        solution.push_back(root->val);
        
        if (sum == 0 && !root->left && !root->right && !solution.empty()) {
            result.push_back(solution);
        }
        
        dfs(root->left, result, solution, sum);
        dfs(root->right, result, solution, sum);
        
        solution.pop_back();
    }
};
