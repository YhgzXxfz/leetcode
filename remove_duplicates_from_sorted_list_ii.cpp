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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode fakeHead(0);
        fakeHead.next = head;
        auto prev = &fakeHead, curr = head, next = head->next;
        
        while (curr) {
            if (next && curr->val == next->val) {
                next = next->next;
            } else if (curr->next != next) {
                curr = next;
                prev->next = next;
                if (next) next = next->next;
            } else {
                prev = curr;
                curr = next;
                if (next) next = next->next;
            }
        }
        return fakeHead.next;
    }
};
