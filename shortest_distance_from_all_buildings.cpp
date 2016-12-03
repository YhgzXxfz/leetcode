class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n,0)), building_nums(m, vector<int>(n,0));
        int buildings = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    buildings++;
                    bfs(grid, i, j, dist, building_nums);
                }
            }
        }
        
        int min_dist = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && dist[i][j] != 0 && building_nums[i][j] == buildings) {
                    min_dist = min(min_dist, dist[i][j]);
                }
            }
        }
        if (min_dist < INT_MAX) return min_dist;
        return -1;
    }

private:
    void bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dist, vector<vector<int>>& building_nums) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(i,j));
        
        vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int level = 0;
        while (!q.empty()) {
            level++;
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                auto pos = q.front();
                q.pop();
                for (auto d : dirs) {
                    int x = pos.first + d[0], y = pos.second + d[1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && grid[x][y] == 0) {
                        visited[x][y] = true;
                        dist[x][y] += level;
                        building_nums[x][y]++;
                        q.push(make_pair(x,y));
                    }
                }
            }
        }
    }
};
