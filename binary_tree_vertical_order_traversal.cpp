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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        result.resize(1);
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        int left = 0, right = 0;
        while (!q.empty()) {
            auto node = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if (left <= col && col <= right) {
                result[col-left].emplace_back(node->val);
            } else if (col < left) {
                left--;
                result.insert(result.begin(), vector<int>());
                result.front().emplace_back(node->val);
            } else {
                right++;
                result.insert(result.end(), vector<int>());
                result.back().emplace_back(node->val);
            }
            
            if (node->left) q.push(make_pair(node->left, col-1));
            if (node->right) q.push(make_pair(node->right, col+1));
        }
        return result;
    }
};
