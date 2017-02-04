/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// one pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if (!head || n == 0) return head;

	auto slow = head, fast = head;
	for (int i = 0; i < n; ++i) {
		if (!fast) return head; // n > length, so remove none
		fast = fast->next;
	}
	if (!fast) return head->next; // n == length, so remove head

	while (fast->next) {
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = slow->next->next;
	return head;
    }
};


// two pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        
        auto begin = head, end = head;
        for (int i = 1; i < n; ++i) {
            if (!end) break;
            end = end->next;
        }
        if (!end) return head;
        
        ListNode fakeHead(0);
        fakeHead.next = head;
        auto prev = &fakeHead;
        while (end->next) {
            prev = begin;
            begin = begin->next;
            end = end->next;
        }
        prev->next = begin->next;
        return fakeHead.next;
    }
};
