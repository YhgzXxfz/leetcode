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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        
        if (!root) return result;
        
        dfs(root, result);
        return result;
    }
    
private:
    int dfs(TreeNode* root, vector<vector<int>>& result) {
        if (!root) return -1;
        
        int height = 1 + max(dfs(root->left, result), dfs(root->right, result));
        if (result.size() < height+1) result.emplace_back(vector<int>());
        result[height].emplace_back(root->val);
        return height;
    }
};
