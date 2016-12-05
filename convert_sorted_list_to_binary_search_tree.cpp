/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        
        auto getMiddle = [](ListNode* begin, ListNode* end) {
            auto fast = begin, slow = begin;
            while (fast != end && fast->next != end) {
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        };
        
        function<TreeNode*(ListNode*, ListNode*)> convert = [&](ListNode * begin, ListNode * end) -> TreeNode * {
            if (!begin || begin == end) return nullptr;
            if (begin->next == end) return new TreeNode(begin->val);
            
            auto mid = getMiddle(begin, end);
            TreeNode * root = new TreeNode(mid->val);
            root->left = convert(begin, mid);
            root->right = convert(mid->next, end);
            return root;
        };
        
        return convert(head, nullptr);
    }
};
