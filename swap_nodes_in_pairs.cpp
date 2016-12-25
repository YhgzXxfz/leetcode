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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode fakeHead(0);
        fakeHead.next = head;
        auto curr = &fakeHead;
        while (curr && curr->next && curr->next->next) {
            curr->next = swap(curr->next);
            curr = curr->next->next;
        }
        return fakeHead.next;
    }
    
    ListNode* swap(ListNode* node) {
        if (!node || !node->next || !node->next->next) return node;
        
        auto curr = node, next = node->next;
        curr->next = next->next;
	next->next = curr;
        return next;
    }
};
