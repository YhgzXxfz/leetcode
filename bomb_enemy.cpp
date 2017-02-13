class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
	if (grid.empty()) return 0;

        int m = grid.size(), n = grid[0].size();
	if (n == 0) return 0;

        int max_kill = 0, row_hits, col_hits[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0 || grid[i][j-1] == 'W') {
                    row_hits = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; ++k) {
                        row_hits += grid[i][k] == 'E';
                    }
                }
                if (i == 0 || grid[i-1][j] == 'W') {
                    col_hits[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; ++k) {
                        col_hits[j] += grid[k][j] == 'E';
                    }
                }
                if (grid[i][j] == '0') max_kill = max(max_kill, row_hits+col_hits[j]);
            }
        }
        return max_kill;
    }
};
