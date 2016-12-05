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
