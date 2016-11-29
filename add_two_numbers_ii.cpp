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
        unordered_map<int, int> mp1, mp2;
        int i = 0, j = 0;
        while (l1) {
            mp1[i] = l1->val;
            i++;
            l1 = l1->next;
        }
        while (l2) {
            mp2[j] = l2->val;
            j++;
            l2 = l2->next;
        }
        
        int carry = 0;
        i--; j--;
        ListNode* head = nullptr;
        while (i >= 0 || j >= 0 || carry > 0) {
            int a = i >= 0 ? mp1[i] : 0;
            int b = j >= 0 ? mp2[j] : 0;
            int sum = a+b+carry;
            carry = sum/10;
            i--; j--;
            
            ListNode* node = new ListNode(sum%10);
            node->next = head;
            head = node;
        }
        return head;
    }
};
