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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getDepth(root), total = getNodeNumber(height);
        
        vector<vector<string>> result(height, vector<string>(total, ""));
        dfs(root, result, 0, total/2, height);
        return result;
    }

private:
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
    
    void dfs(TreeNode* root, vector<vector<string>>& result, int level, int col, int height) {
        if (!root || level >= height) return ;
        
        result[level][col] = to_string(root->val);
        
        int offset = 1 + getNodeNumber(height-1 - (level+1));
        dfs(root->left, result, level+1, col-offset, height);
        dfs(root->right, result, level+1, col+offset, height);
    }
    
    int getNodeNumber(int height) { return pow(2, height) -1; }
};
