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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        
        int count = 1;
        auto curr = head;
        while (curr->next) {
            count++;
            curr = curr->next;
        }
        
        curr->next = head;
        
        curr = head;
        k %= count;
        for (int i = 0; i < count-1 -k; ++i) {
            curr = curr->next;
        }
        auto rot = curr->next;
        curr->next = nullptr;
        return rot;
    }
};
