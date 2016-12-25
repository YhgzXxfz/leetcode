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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        
        auto begin = head, end = head;
        for (int i = 1; i < n; ++i) {
            if (!end) break;
            end = end->next;
        }
        if (!end) return head;
        
        ListNode fakeHead(0);
        fakeHead.next = head;
        auto prev = &fakeHead;
        while (end->next) {
            prev = begin;
            begin = begin->next;
            end = end->next;
        }
        prev->next = begin->next;
        return fakeHead.next;
    }
};
