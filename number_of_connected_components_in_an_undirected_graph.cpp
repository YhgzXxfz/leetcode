class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n);
        for (int i = 0; i < n; ++i) {
            roots[i] = i;
        }
        
        for (auto& edge : edges) {
            int x = find(roots, edge.first);
            int y = find(roots, edge.second);
            if (x != y) {
                roots[x] = y;
                n--;
            }
        }
        return n;
    }

private:
    int find(vector<int>& roots, int id) {
        while (roots[id] != id) {
            roots[id] = roots[roots[id]];
            id = roots[id];
        }
        return id;
    }
};
