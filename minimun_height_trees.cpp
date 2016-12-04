class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return vector<int>(1, 0);
        
        vector<unordered_set<int>> adjacents(n);
        for (auto edge : edges) {
            adjacents[edge.first].insert(edge.second);
            adjacents[edge.second].insert(edge.first);
        }
        
        vector<int> leaves;
        for (int i = 0 ; i < adjacents.size(); ++i) {
            if (adjacents[i].size() == 1) leaves.push_back(i);
        }
        
        while (n > 2) {
            n -= leaves.size();
            vector<int> new_leaves;
            for (auto leave : leaves) {
                for (auto neighbor : adjacents[leave]) {
                    adjacents[neighbor].erase(leave);
                    if (adjacents[neighbor].size() == 1) new_leaves.push_back(neighbor);
                }
            }
            if (new_leaves.empty()) return leaves;
            leaves = new_leaves;
        }
        return leaves;
    }
};
