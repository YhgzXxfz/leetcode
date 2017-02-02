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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        int max_occur = dfs(root, mp);
        
        vector<int> result;
        for (auto& entry : mp) {
            if (entry.second == max_occur) result.emplace_back(entry.first);
        }
        return result;
    }

private:
    int dfs(TreeNode* root, unordered_map<int, int>& mp) {
        if (!root) return 0;
        
        mp[root->val]++;
        return max(mp[root->val], max(dfs(root->left, mp), dfs(root->right, mp)));
    }
};
