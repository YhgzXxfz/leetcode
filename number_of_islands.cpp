class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for (int i = 0;i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    findIsland(i, j, grid);
                    ++count;
                }
            }
        }
        return count;
    }
    
    void findIsland(int i , int j, vector<vector<char>>& grid) {
        grid[i][j] = '0';
        
        if (i > 0 && grid[i-1][j] == '1') findIsland(i-1, j, grid);
        if (i < grid.size()-1 && grid[i+1][j] == '1') findIsland(i+1, j, grid);
        if (j > 0 && grid[i][j-1] == '1') findIsland(i, j-1, grid);
        if (j < grid[0].size()-1 && grid[i][j+1] == '1') findIsland(i, j+1, grid);
    }
};
