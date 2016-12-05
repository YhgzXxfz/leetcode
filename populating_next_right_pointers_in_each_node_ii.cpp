/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode dummy(0);
            auto prev = &dummy;
            while (root) {
                if (root->left) {
                    prev->next = root->left;
                    prev = prev->next;
                }
                if (root->right) {
                    prev->next = root->right;
                    prev = prev->next;
                }
                root = root->next;
            }
            root = dummy.next;
        }
    }
};
