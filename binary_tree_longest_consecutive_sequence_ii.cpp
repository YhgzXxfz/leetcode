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
    int longestConsecutive(TreeNode* root) {
        int max_len = 0;
        dfs(root, max_len);
        return max_len;
    }

private:
    pair<int, int> dfs(TreeNode* root, int& max_len) {
        if (!root) return make_pair(0,0);
        
        int inc = 1, dec = 1;
        if (root->left) {
            auto l = dfs(root->left, max_len);
            if (root->left->val +1 == root->val) inc = l.first+1;
            else if (root->left->val -1 == root->val) dec = l.second+1;
        }
        
        if (root->right) {
            auto r = dfs(root->right, max_len);
            if (root->right->val +1 == root->val) inc = max(inc, r.first+1);
            else if (root->right->val -1 == root->val) dec = max(dec, r.second+1);
        }
        
        max_len = max(max_len, inc+dec-1);
        return make_pair(inc, dec);
    }
};
