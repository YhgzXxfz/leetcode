class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return result;
        
        int m = matrix.size(), n = matrix[0].size();
        visited.resize(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            dfs(matrix, i, 0, INT_MIN, 1);
            dfs(matrix, i, n-1, INT_MIN, 2);
        }
        
        for (int j = 0; j < n; ++j) {
            dfs(matrix, 0, j, INT_MIN, 1);
            dfs(matrix, m-1, j, INT_MIN, 2);
        }
        return result;
    }

private:
    void dfs(vector<vector<int>>& matrix, int x, int y, int prev, int mask) {
        int m = matrix.size(), n = matrix[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] < prev || (visited[x][y] & mask) == mask) return;
        
        visited[x][y] |= mask;
        if (visited[x][y] == 3) result.push_back(make_pair(x, y));
        dfs(matrix, x-1, y, matrix[x][y], visited[x][y]);
        dfs(matrix, x, y+1, matrix[x][y], visited[x][y]);
        dfs(matrix, x+1, y, matrix[x][y], visited[x][y]);
        dfs(matrix, x, y-1, matrix[x][y], visited[x][y]);
    }
    
    vector<pair<int, int>> result;
    vector<vector<int>> visited;
};
