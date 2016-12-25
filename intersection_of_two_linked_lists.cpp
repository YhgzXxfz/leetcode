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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        int len1 = 0, len2 = 0;
        auto pA = headA, pB = headB;
        while (pA->next) {
            pA = pA->next;
            ++len1;
        }
        while (pB->next) {
            pB = pB->next;
            ++len2;
        }
        
        pA = headA;pB = headB;
        int diff = abs(len1-len2);
        if (len1 > len2) {
            for (int i = 0; i < diff; ++i) pA = pA->next;
        } else {
            for (int i = 0; i < diff; ++i) pB = pB->next;
        }
        
        while (pA) {
            if (pA == pB) return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return nullptr;
    }
};
