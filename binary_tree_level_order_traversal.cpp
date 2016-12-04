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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bfs(root, result, 1);
        return result;
    }
    
    void bfs(TreeNode* root, vector<vector<int>>& result, int level) {
        if (!root) return;
        
        if (level > result.size()) result.emplace_back(vector<int>());
        
        result[level-1].emplace_back(root->val);
        bfs(root->left, result, level+1);
        bfs(root->right, result, level+1);
    }
};
