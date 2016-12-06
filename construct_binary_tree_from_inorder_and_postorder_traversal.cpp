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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
        
        return dfs(mp, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
    TreeNode* dfs(unordered_map<int, int>& mp, vector<int>& postorder, int li, int ri, int lp, int rp) {
        if (lp > rp) return nullptr;
        if (lp == rp) return new TreeNode(postorder[lp]);
        
        int root_val = postorder[rp];
        auto root = new TreeNode(root_val);
        int mi = mp[root_val];
        int left = mi-li, right = ri-mi;
        
        root->left = dfs(mp, postorder, li, mi-1, lp, lp+left-1);
        root->right = dfs(mp, postorder, mi+1, ri, rp-right, rp-1);
        return root;
    }
};
