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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]] = i;
        }
        return dfs(nums, 0, nums.size()-1, mp);
    }

private:
    TreeNode* dfs(vector<int>& nums, int left, int right, unordered_map<int, int>& mp) {
        if (left > right) return nullptr;
        if (left == right) return new TreeNode(nums[left]);
        
        int max_elem = *max_element(nums.begin()+left, next(nums.begin()+right)), id = mp[max_elem];
        auto root = new TreeNode(max_elem);
        root->left = dfs(nums, left, id-1, mp);
        root->right = dfs(nums, id+1, right, mp);
        return root;
    }
};
