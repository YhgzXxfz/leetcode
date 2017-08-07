/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// dfs
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        dfs(root, nums);
        
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }
        return false;
    }

private:
    void dfs(TreeNode* root, vector<int>& nums) {
        if (!root) return ;
        
        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
    }
};
