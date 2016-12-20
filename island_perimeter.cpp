class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size(), n = grid[0].size();
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    if (i == 0) sum++;
                    if (i == m-1) sum++;
                    if (j == 0) sum++;
                    if (j == n-1) sum++;
                    
                    if (i > 0 && !grid[i-1][j]) sum++;
                    if (i < m-1 && !grid[i+1][j]) sum++;
                    if (j > 0 && !grid[i][j-1]) sum++;
                    if (j < n-1 && !grid[i][j+1]) sum++;
                }
            }
        }
        return sum;
    }
};
