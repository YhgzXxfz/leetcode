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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
        return dfs(mp, preorder, 0, inorder.size()-1, 0, preorder.size()-1);
    }
    
    TreeNode* dfs(unordered_map<int, int>& mp, vector<int>& preorder, int li, int ri, int lp, int rp) {
        if (lp > rp) return nullptr;
        if (lp == rp) return new TreeNode(preorder[lp]);
        
        int root_val = preorder[lp];
        auto root = new TreeNode(root_val);
        int mi = mp[root_val];
        int left = mi-li, right = ri-mi;
        
        root->left = dfs(mp, preorder, li, mi-1, lp+1, lp+left);
        root->right = dfs(mp, preorder, mi+1, ri, rp-right+1, rp);
        return root;
    }
};
