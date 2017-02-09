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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        auto mid = getMiddle(head);
        auto rev = reverse(mid->next);

        mid->next = rev;
        while (head && rev) {
            if (head->val != rev->val) return false;
            head = head->next;
            rev = rev->next;
        }
        return true;
    }

private:    
    ListNode* getMiddle(ListNode* head) {
        if (!head || !head->next) return head;
        auto fast = head, slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head) {
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
