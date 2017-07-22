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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        
        if (sameTree(s, t)) return true;
        auto left = isSubtree(s->left, t), right = isSubtree(s->right, t);
        return left || right;
    }

private:
    bool sameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        
        auto l = sameTree(s->left, t->left), r = sameTree(s->right, t->right);
        return s->val == t->val && l && r;
    }
};
