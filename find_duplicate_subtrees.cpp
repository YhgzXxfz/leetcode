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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> mp;
        serialize(root, mp);
        
        vector<TreeNode*> result;
        for (auto entry : mp) {
            if (entry.second.size() > 1) result.push_back(entry.second[0]);
        }
        return result;
    }

private:
    string serialize(TreeNode* root, unordered_map<string, vector<TreeNode*>>& mp) {
        if (!root) return "";
        
        string s = "(" + serialize(root->left, mp) + to_string(root->val) + serialize(root->right, mp) + ")";
        mp[s].push_back(root);
        return s;
    }
};
