class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> result;
        roots = vector<int>(m*n, -1);
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int island = 0;
        for (auto pos : positions) {
            int x = pos.first, y = pos.second, idx_p = x*n + y;
            roots[idx_p] = idx_p;
            ++island;
            for (auto dir : dirs) {
                int row = x+dir.first, col = y+dir.second, idx_new = row*n + col;
                if (row >= 0 && row < m && col >= 0 && col < n && roots[idx_new] != -1) {
                    int rootNew = findRoot(idx_new), rootPos = findRoot(idx_p);
                    if (rootPos != rootNew) {
                        roots[rootPos] = rootNew;
                        --island;
                    }
                }
            }
            result.push_back(island);
        }
        return result;
    }

private:
    int findRoot(int id) {
        while (roots[id] != id) {
            roots[id] = roots[roots[id]];
            id = roots[id];
        }
        return id;
    }
    
    vector<int> roots;
};
