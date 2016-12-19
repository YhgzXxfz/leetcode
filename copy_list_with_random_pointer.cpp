/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        
        unordered_map<RandomListNode*, RandomListNode*> record;
        
        auto getPtr = [&](RandomListNode* pt)->RandomListNode* {
            if (!pt) return nullptr;
            auto ex = record.find(pt);
            if (ex != record.end()) return ex->second;
            
            auto newPtr = new RandomListNode(pt->label);
            record[pt] = newPtr;
            return newPtr;
        };
        
        RandomListNode fakeHead(0);
        auto curr = head, newPtr = &fakeHead;
        while (curr) {
            newPtr->next = getPtr(curr);
            newPtr->next->random = getPtr(curr->random);
            curr = curr->next;
            newPtr = newPtr->next;
        }
        return fakeHead.next;
    }
};
