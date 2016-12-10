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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode fakeHead(INT_MIN);
        fakeHead.next = head;
        auto curr = head->next;
        head->next = nullptr;
        
        while(curr) {
            auto prev = &fakeHead, next = curr->next, sorted = fakeHead.next;
            while (prev) {
                if (!sorted) {
                    prev->next = curr;
                    curr->next = nullptr;
                    break;
                }
                
                if (prev->val <= curr->val && curr->val < sorted->val) {
                    prev->next = curr;
                    curr->next = sorted;
                    break;
                } else {
                    prev = sorted;
                    sorted = sorted->next;
                }
            }
            curr = next;
        }
        return fakeHead.next;
    }
};
