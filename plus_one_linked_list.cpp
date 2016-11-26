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
    ListNode* plusOne(ListNode* head) {
        return reverse(plus(reverse(head)));
    }

private:
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        
        auto curr = head, next = head, prev = head;
        while (next) {
            prev = curr;
            curr = next;
            next = next->next;
            
            curr->next = prev;
            if (prev == head) prev->next = nullptr;
        }
        return curr;
    }
    
    ListNode* plus(ListNode* head) {
        auto curr = head, prev = head;
        int carry = 1;
        while (carry && curr) {
            int sum = curr->val+carry;
            curr->val = sum % 10;
            carry = sum / 10;
            
            prev = curr;
            curr = curr->next;
        }
        if (carry) prev->next = new ListNode(carry);
        return head;
    }
};
