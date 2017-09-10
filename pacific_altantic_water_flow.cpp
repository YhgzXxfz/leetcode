// bfs
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> result;
        if (matrix.empty()) return result;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0)), atlantic(m, vector<int>(n, 0));
        
        queue<pair<int,int>> q_pacific, q_atlantic;
        for (int i = 0; i < m; ++i) {
            q_pacific.push(make_pair(i, 0));
            q_atlantic.push(make_pair(i, n-1));
            pacific[i][0] = 1;
            atlantic[i][n-1] = 1;
        }
        
        for (int j = 0; j < n; ++j) {
            q_pacific.push(make_pair(0,j));
            q_atlantic.push(make_pair(m-1, j));
            pacific[0][j] = 1;
            atlantic[m-1][j] = 1;
        }
        
        bfs(matrix, q_pacific, pacific);
        bfs(matrix, q_atlantic, atlantic);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back(make_pair(i,j));
                }
            }
        }
        return result;
    }
    
private:
    void bfs(vector<vector<int>>& matrix, queue<pair<int,int>>& q, vector<vector<int>>& visited) {
        int m = matrix.size(), n = matrix[0].size();
        while (!q.empty()) {
            auto curr = q.front();
            int i = curr.first, j = curr.second;
            q.pop();
            
            for (auto dir : dirs) {
                int x = i+dir[0], y = j+dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] >= matrix[i][j] && !visited[x][y]) {
                    q.push(make_pair(x,y));
                    visited[x][y] = true;
                }
            }
        }
    }
    
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {0,-1}, {1,0}};
};


// dfs
/*
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> result;
        if (matrix.empty()) return result;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0)), atlantic = pacific;
        
        for (int i = 0; i < m; ++i) {
            dfs(matrix, i, 0, INT_MIN, pacific);
            dfs(matrix, i, n-1, INT_MIN, atlantic);
        }
        
        for (int j = 0; j < n; ++j) {
            dfs(matrix, 0, j, INT_MIN, pacific);
            dfs(matrix, m-1, j, INT_MIN, atlantic);
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back(make_pair(i,j));
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>>& matrix, int i, int j, int prev, vector<vector<int>>& visited) {
        int m = matrix.size(), n = matrix[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || matrix[i][j] < prev) return ;
        visited[i][j] = true;
        
        for (auto dir : dirs) {
            dfs(matrix, i+dir[0], j+dir[1], matrix[i][j], visited);
        }
    }
    
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {0,-1}, {1,0}};
};
*/
