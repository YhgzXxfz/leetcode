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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        
        ListNode small(0), large(0);
        auto s = &small, l = &large, curr = head;
        
        while (curr) {
            if (curr->val < x) {
                s->next = curr;
                s = s->next;
            } else {
                l->next = curr;
                l = l->next;
            }
            curr = curr->next;
        }
        s->next = large.next;
        l->next = nullptr;
        return small.next;
    }
};
