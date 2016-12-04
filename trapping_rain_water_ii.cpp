class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        visited.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                    pq.push(make_pair(heightMap[i][j], i*n+j));
                    visited[i][j] = 1;
                }
            }
        }
        
        int result = 0;
        vector<vector<int>> directions{{0,1}, {1,0}, {0,-1}, {-1,0}};
        while (!pq.empty()) {
            auto val = pq.top();
            pq.pop();
            int height = val.first, x = val.second/n, y = val.second%n;
            max_height = max(max_height, height);
            for (auto& dir : directions) {
                int new_x = x+dir[0], new_y = y+dir[1];
                if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || visited[new_x][new_y]) continue;
                
                if (max_height > heightMap[new_x][new_y]) result += (max_height-heightMap[new_x][new_y]);
                pq.push(make_pair(heightMap[new_x][new_y], new_x*n+new_y));
                visited[new_x][new_y] = 1;
            }
        }
        return result;
    }

private:
    int max_height = INT_MIN;
    vector<vector<int>> visited;
};
