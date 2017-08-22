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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        vector<pair<int,int>> widths;
        return dfs(root, 0, 1, widths);
    }

private:
    int dfs(TreeNode* root, int level, int order, vector<pair<int,int>>& widths) {
        if (!root) return 0;
        
        if (level >= widths.size()) widths.push_back(make_pair(order, order));
        else widths[level].second = order;
        
        return max({widths[level].second - widths[level].first +1, dfs(root->left, level+1, 2*order, widths), dfs(root->right, level+1, 2*order+1,widths)});
    }
};
