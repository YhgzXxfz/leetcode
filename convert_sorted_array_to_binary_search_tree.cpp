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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        
        return dfs(nums, 0, len);
    }
    
    TreeNode* dfs(vector<int>& nums, int begin, int end) {
        if (begin >= end) return nullptr;
        
        if (begin+1 == end) return new TreeNode(nums[begin]);
        
        int mid = begin + (end-begin)/2;
        auto root = new TreeNode(nums[mid]);
        root->left = dfs(nums, begin, mid);
        root->right = dfs(nums, mid+1, end);
        
        return root;
    }
};
