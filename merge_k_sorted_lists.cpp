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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode fakeHead(0);
        auto curr = &fakeHead;
        
        vector<ListNode*> heap;
        for (auto node : lists) {
            if (node) heap.push_back(node);
        }
        auto comp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        make_heap(heap.begin(), heap.end(), comp);
        
        while(!heap.empty()) {
            pop_heap(heap.begin(), heap.end(), comp);
            auto small = heap.back();
            curr->next = small;
            heap.pop_back();
            curr = curr->next;
            
            small = small->next;
            if (small) {
                heap.push_back(small);
                push_heap(heap.begin(), heap.end(), comp);
            }
        }
        curr->next = nullptr;
        return fakeHead.next;
    }
};
