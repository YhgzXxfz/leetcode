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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoLists(l1, l2, 0);
    }

private:    
    ListNode* addTwoLists(ListNode* l1, ListNode* l2, int carry) {
        if (!l1) return addOneList(l2, carry);
        if (!l2) return addOneList(l1, carry);
        
        int sum = l1->val + l2->val + carry;
        auto node = new ListNode(sum%10);
        node->next = addTwoLists(l1->next, l2->next, sum/10);
        return node;
    }
    
    ListNode* addOneList(ListNode* l, int carry) {
        if (!l && carry == 0) return nullptr;
        else if (!l) return new ListNode(carry);
        
        int sum = l->val + carry;
        auto node = new ListNode(sum%10);
        node->next = addOneList(l->next, sum/10);
        return node;
    }
};
