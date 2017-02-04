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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;
        
        int count = 0;
        ListNode fakeHead(0);
        fakeHead.next = head;
        auto prev = &fakeHead, curr = head;
        while (curr) {
            count++;
            if (count % k == 0) {
                auto last = prev->next, next = curr->next;
                prev->next = reverse(prev->next, curr->next);
                last->next = next;
                prev = last;
                curr = next;
            } else {
                curr = curr->next;
            }
        }
        return fakeHead.next;
    }

private:    
    ListNode* reverse(ListNode* begin, ListNode* end) {
        if (!begin || begin == end || begin->next == end) return begin;
        
        auto next = begin->next;
        auto rev = reverse(next, end);
        next->next = begin;
        begin->next = nullptr;
        return rev;
    }
};
