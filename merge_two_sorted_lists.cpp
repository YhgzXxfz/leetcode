/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// iterative
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;

		ListNode fakeHead(0), *curr = &fakeHead;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				curr->next = l1;
				l1 = l1->next;
			} else {
				curr->next = l2;
				l2 = l2->next;
			}
			curr = curr->next;
		}
		if (l1) curr->next = l1;
		if (l2) curr->next = l2;
		return fakeHead.next;
	}
};


// recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
