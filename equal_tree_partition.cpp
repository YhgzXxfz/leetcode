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
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> mp;
        int sum = dfs(root, mp);
        if (sum == 0) return mp[sum] > 1;
        return sum %2 == 0 && mp.find(sum/2) != mp.end();
    }
    
private:
    int dfs(TreeNode* root, unordered_map<int, int>& mp) {
        if (!root) return 0;
        
        int sum = root->val + dfs(root->left, mp) + dfs(root->right, mp);
        mp[sum]++;
        return sum;
    }
};
