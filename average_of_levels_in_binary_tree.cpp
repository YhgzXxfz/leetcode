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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> nodes;
        dfs(root, nodes, 0);
        
        vector<double> result;
        for (const auto& level : nodes ) {
            double ave = 0;
            for (int i = 0; i < level.size(); ++i) {
                ave += (level[i]-ave) / (i+1);
            }
            result.push_back(ave);
        }
        return result;
    }

private:
    void dfs(TreeNode* root, vector<vector<int>>& nodes, int level) {
        if (!root) return ;
        
        if (level >= nodes.size()) nodes.emplace_back(vector<int>());
        nodes[level].push_back(root->val);
        
        dfs(root->left, nodes, level+1);
        dfs(root->right, nodes, level+1);
    }
};
