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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return dfs(1, n);
    }
    
private:
    vector<TreeNode*> dfs(int begin, int end) {
        vector<TreeNode*> result;
        if (begin > end) {
            result.emplace_back(nullptr);
            return result;
        }
        
        for (int i = begin; i <= end; ++i) {
            auto left = dfs(begin, i-1);
            auto right = dfs(i+1, end);
            
            for (auto l : left) {
                for (auto r : right) {
                    auto root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.emplace_back(root);
                }
            }
        }
        return result;
    }
};
