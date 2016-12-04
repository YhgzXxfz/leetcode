/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // 1 DFS
        /*
        if (!node) return node;
        if (mp.find(node) == mp.end()) {
            mp[node] = new UndirectedGraphNode(node->label);
            for (auto neighbor : node->neighbors) {
                (mp[node]->neighbors).push_back(cloneGraph(neighbor));
            }
        }
        return mp[node];
        */
        
        // BFS
        if (!node) return node;
        mp[node] = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> q;
        q.push(node);
        
        while (!q.empty()) {
            UndirectedGraphNode* curr = q.front();
            q.pop();
            for (auto neighbor : curr->neighbors) {
                if (mp.find(neighbor) == mp.end()) {
                    mp[neighbor] = new UndirectedGraphNode(neighbor->label);
                    q.push(neighbor);
                }
                (mp[curr]->neighbors).push_back(mp[neighbor]);
            }
        }
        return mp[node];
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
};
