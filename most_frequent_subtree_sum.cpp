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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> freq;
        int max_freq = INT_MIN;
        calculateSubtreeSums(root, freq, max_freq);
        
        vector<int> result;
        for (auto entry : freq) {
            if (entry.second == max_freq) result.push_back(entry.first);
        }
        return result;
    }

private:
    int calculateSubtreeSums(TreeNode* root, unordered_map<int, int>& mp, int& max_freq) {
        if (!root) return 0;
        
        int sum = root->val;
        sum += calculateSubtreeSums(root->left, mp, max_freq) + calculateSubtreeSums(root->right, mp, max_freq);
        mp[sum]++;
        max_freq = max(max_freq, mp[sum]);
        return sum;
    }
};
