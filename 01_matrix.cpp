class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0)), output(m, vector<int>(n, 0));
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push(make_pair(i, j));
                }
            } 
        }
        
        int depth = 1;
        vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        while (!q.empty()) {
            int curr_size = q.size();
            for (int k = 0; k < curr_size; ++k) {
                auto curr = q.front();
                q.pop();
                int i = curr.first, j = curr.second;
                for (const auto& dir : dirs) {
                    int x = i+dir[0], y = j+dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
                    
                    output[x][y] = depth;
                    visited[x][y] = true;
                    q.push(make_pair(x,y));
                }
            }
            depth++;
        }
        return output;
    }
};
