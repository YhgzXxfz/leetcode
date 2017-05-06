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
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> level_traversal;
        dfs(root, level_traversal, 0);
        
        return findLargest(level_traversal);
    }

private:
    void dfs(TreeNode* root, vector<vector<int>>& level_traversal, int level) {
        if (!root) return ;
        
        if (level >= level_traversal.size()) level_traversal.push_back(vector<int>());
        level_traversal[level].push_back(root->val);
        dfs(root->left, level_traversal, level+1);
        dfs(root->right, level_traversal, level+1);
    }
    
    vector<int> findLargest(vector<vector<int>> level_traversal) {
        vector<int> result;
        for (auto level_values : level_traversal) {
            result.push_back(*max_element(level_values.begin(), level_values.end()));
        }
        return result;
    }
};
