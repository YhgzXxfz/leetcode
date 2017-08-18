class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size(), min_dist = INT_MAX;
        vector<vector<int>> dists(m, vector<int>(n, -1));
        dists[start[0]][start[1]] = 0;
        
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        queue<pair<int,int>> q;
        q.push(make_pair(start[0], start[1]));
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            for (auto dir : dirs) {
                int x = curr.first, y = curr.second;
                int count = 0;
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                    x += dir[0]; y += dir[1]; ++count;
                }
                x -= dir[0]; y -= dir[1]; --count;
                
                if (dists[x][y] == -1 || dists[x][y] > dists[curr.first][curr.second] + count) {
                    dists[x][y] = dists[curr.first][curr.second] + count;
                    q.push(make_pair(x,y));
                }
            }
        }
        
        return dists[destination[0]][destination[1]];
    }
};
