class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> matrix(n);
        for (auto edge : edges) {
            matrix[edge.first].emplace_back(edge.second);
            matrix[edge.second].emplace_back(edge.first);
        }
        
        vector<int> path(n, 0);
        path[0] = 1;
        
        if (hasCycle(matrix, path, 0, -1)) return false;
        if (accumulate(path.begin(), path.end(), 0) < n) return false;
        return true;
    }

private:
    bool hasCycle(vector<vector<int>>& matrix, vector<int>& path, int src, int prev) {
        for (auto i : matrix[src]) {
            if (i != prev) {
                if (path[i] == 1) return true;
                path[i] = 1;
                if (hasCycle(matrix, path, i, src)) return true;
            }
        }
        return false;
    }
};
