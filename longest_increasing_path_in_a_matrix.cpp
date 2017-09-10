class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        
        int max_path = INT_MIN, len = 1;
        vector<vector<int>> cache(m, vector<int> (n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                len = dfs(matrix, i, j, cache);
                max_path = max(max_path, len);
            }
        }
        return max_path;
    }

private:
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& cache) {
        if (cache[i][j] != 0) return cache[i][j];
        
        int m = matrix.size(), n = matrix[0].size();
        int max_len = 1;
        for (auto dir : dirs) {
            int x = i+dir[0], y = j+dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                max_len = max(max_len, 1+dfs(matrix, x, y, cache));
            }
        }
        cache[i][j] = max_len;
        return max_len;
    }
    
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
};
