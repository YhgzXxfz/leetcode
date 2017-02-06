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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bfs(root, result, 1, true);
        return result;
    }

private:    
    void bfs(TreeNode* root, vector<vector<int>>& result, int level, bool lToR) {
        if (!root) return;
        
        if (level > result.size()) result.push_back(vector<int>());
        
        if (lToR) result[level-1].push_back(root->val);
        else result[level-1].insert(result[level-1].begin(), root->val);
        
        bfs(root->left, result, level+1, !lToR);
        bfs(root->right, result, level+1, !lToR);
    }
};
