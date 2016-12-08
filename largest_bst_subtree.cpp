/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Data {
    int size;
    int lower;
    int upper;
    Data(int size = 0, int lower = INT_MAX, int upper = INT_MIN) : size(size), lower(lower), upper(upper) {}
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;

        helper(root);
        return max_size;
    }
    
private:
    Data* helper(TreeNode* root) {
        if (!root) return new Data();
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        if (left->size == -1 || right->size == -1 || root->val <= left->upper || root->val >= right->lower) {
            return new Data(-1, 0, 0);
        }
        
        int size = left->size + 1 + right->size;
        max_size = max(max_size, size);
        return new Data(size, min(left->lower, root->val), max(right->upper, root->val));
    }
    
    int max_size = 0;
};
