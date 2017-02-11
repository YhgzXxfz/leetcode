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
