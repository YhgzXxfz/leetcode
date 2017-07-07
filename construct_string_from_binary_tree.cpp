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
    string tree2str(TreeNode* t) {
        if (!t) return "";
        
        string s = "";
        dfs(t, s);
        return s.substr(1, s.size()-2);
    }

private:
    void dfs(TreeNode* root, string& s) {
        if (!root) return ;
        
        s += "(" + to_string(root->val);
        
	if (root->left && root->right) {
            dfs(root->left, s);
            dfs(root->right, s);
        }
        
        if (root->left && !root->right) {
            dfs(root->left, s);
        }
        
        if (!root->left && root->right) {
            s += "()";
            dfs(root->right, s);
        }
        
        s += ")";
    }
};
