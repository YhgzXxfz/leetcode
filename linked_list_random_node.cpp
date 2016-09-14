class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        while(head) {
            length++;
            head = head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int index = rand() % length;
        auto curr = this->head;
        while (index-- > 0) {
            curr = curr->next;
        }
        return curr->val;
    }
    
private:
    // 1 Use a container to store all values of the linked list
    // vector<int> data;
    // 2 Use a head pointer and save the length
    ListNode * head;
    int length = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
