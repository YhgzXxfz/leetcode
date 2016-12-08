/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return pathSum(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:
    int pathSum(TreeNode* root, int prev, int& sum) {
        if (!root) return 0;
        int curr = prev + root->val;
        return (curr == sum) + pathSum(root->left, curr, sum) + pathSum(root->right, curr, sum);
    }
};
*/
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        return pathSum(root, sum, 0);
    }
    
private:
    int pathSum(TreeNode* root, int sum, int prev) {
        if (!root) return 0;
        root->val += prev;
        int count = (root->val == sum) + (mp.count(root->val - sum) ? mp[root->val - sum] : 0);
        mp[root->val]++;
        count += pathSum(root->left, sum, root->val) + pathSum(root->right, sum, root->val);
        mp[root->val]--;
        return count;
    }
    
    unordered_map<int, int> mp;
};
