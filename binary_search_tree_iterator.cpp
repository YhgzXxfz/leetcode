/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> _stack;
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            _stack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto curr = _stack.top();
        _stack.pop();
        int result = curr->val;
        
        if (curr->right) {
            curr = curr->right;
            while (curr) {
                _stack.push(curr);
                curr = curr->left;
            }
        }
        return result;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
