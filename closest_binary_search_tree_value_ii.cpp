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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double, int>> pq;
        
        closestKValues(root, target, k, pq);
        vector<int> result;
        while (!pq.empty()) {
            result.emplace_back(pq.top().second);
            pq.pop();
        }
        return result;
    }

private:
    void closestKValues(TreeNode* root, double target, int k, priority_queue<pair<double, int>>& pq) {
        if (!root) return;
        
        double diff = abs(target - root->val);
        pq.push(make_pair(diff, root->val));
        if (pq.size() > k) pq.pop();
        
        closestKValues(root->left, target, k, pq);
        closestKValues(root->right, target, k, pq);
    }
};
