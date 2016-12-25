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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        auto mid = getMiddle(head);
        auto rev = reverse(mid->next);
        mid->next = nullptr;
        
        auto curr = head;
        while (curr) {
            auto next = curr->next;
            if (rev) {
                auto rev_next = rev->next;
                curr->next = rev;
                rev->next = next;
                rev = rev_next;
            }
            curr = next;
        }
    }
    
    ListNode* getMiddle(ListNode* head) {
        if (!head || !head->next) return head;
        auto fast = head, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        
        auto next = head->next;
        auto rev = reverse(next);
        next->next = head;
        head->next = nullptr;
        return rev;
    }
};
