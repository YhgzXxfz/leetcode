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
    int longestConsecutive(TreeNode* root) {
        return longestConsecutive(root, nullptr, 0);
    }

private:
    int longestConsecutive(TreeNode* curr, TreeNode* prev, int len) {
        if (!curr) return len;
        len = (prev && curr->val == prev->val + 1) ? len+1 : 1;
        return max(len, max(longestConsecutive(curr->left, curr, len), longestConsecutive(curr->right, curr, len)));
    }
};
