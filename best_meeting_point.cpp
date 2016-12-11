class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        
        vector<int> rows, cols;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rows.emplace_back(i);
                    cols.emplace_back(j);
                }
            }
        }
        
        int len = rows.size(), dist = 0;
        sort(cols.begin(), cols.end());
        
        int best_row = rows[len/2], best_col = cols[len/2];
        for (auto row : rows) dist += abs(row - best_row);
        for (auto col : cols) dist += abs(col - best_col);
        return dist;
    }
};
