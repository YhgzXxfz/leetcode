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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        
        auto prev = head, curr = head, next = head->next;
        while (next) {
            prev = curr;
            curr = next;
            next = next->next;
            
            curr->next = prev;
            if (prev == head) prev->next = nullptr;
        }
        return curr;
    }
};
