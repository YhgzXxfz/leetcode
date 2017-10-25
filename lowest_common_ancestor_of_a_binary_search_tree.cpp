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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;
        if (max(p->val, q->val) < root->val) return lowestCommonAncestor(root->left, p, q);
        else if (min(p->val, q->val) > root->val) return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};

class Solution { 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto curr = root;
        while (true) {
            if (p->val < curr->val && q->val < curr->val)
                curr = curr->left;
            else if (p->val > curr->val && q->val > curr->val)
                curr = curr->right;
            else return curr; 
        }
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;

		auto path_p = getPath(root, p), path_q = getPath(root, q);
		auto lca = root;
		while (!path_p.empty() && !path_q.empty()) {
			auto curr_p = path_p.front();
			path_p.pop();
			auto curr_q = path_q.front();
			path_q.pop();
			if (curr_p != curr_q) return lca;
			lca = curr_p;
		}
		return lca;
	}

private:
	queue<TreeNode*> getPath(TreeNode* root, TreeNode* p) {
		queue<TreeNode*> q;
		auto curr = root;
		while (curr) {
			q.push(curr);
			if (p->val == curr->val) break;
			else if (p->val < curr->val) curr = curr->left;
			else curr = curr->right;
		}
		return q;
    }
};
