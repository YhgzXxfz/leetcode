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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next) return head;
        
        auto prev = head, curr = head, next = head->next, lastHead = head, lastTail = head;
        for (int i = 1; i < m; ++i) {
            prev = curr;
            curr = next;
            next = next->next;
        }
        lastHead = prev;
        lastTail = curr;
        
        for (int i = m; i < n; ++i) {
            prev = curr;
            curr = next;
            next = next->next;
            
            curr->next = prev;
        }
        
        lastTail->next = next;
        if (m == 1) {
            head = curr;
        } else {
            lastHead->next = curr;
        }
        return head;
    }
};
