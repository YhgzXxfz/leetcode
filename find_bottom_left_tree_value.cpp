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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr = nullptr;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (curr->right) q.push(curr->right);
            if (curr->left) q.push(curr->left);
        }
        return curr->val;
    }
};




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
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> results;
        traverseByLevel(root, results, 0);
        return *(results.back().begin());
    }

private:
    void traverseByLevel(TreeNode* root, vector<vector<int>>& results, int level) {
        if (!root) return ;
        
        if (level >= results.size()) results.push_back(vector<int>());
        results[level].push_back(root->val);
        traverseByLevel(root->left, results, level+1);
        traverseByLevel(root->right, results, level+1);
    }
};
