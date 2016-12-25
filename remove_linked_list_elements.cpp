/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        
        ListNode fakeHead(0);
        fakeHead.next = head;
        auto prev = &fakeHead, curr = head;
        
        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return fakeHead.next;
    }
};
