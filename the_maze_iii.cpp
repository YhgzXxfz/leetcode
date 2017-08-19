class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size(), min_dist = INT_MAX;
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
        vector<vector<string>> ways(m, vector<string>(n, ""));
        dists[ball[0]][ball[1]] = 0;
        
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<char> way = {'r', 'd', 'l', 'u'};
        
        auto comp = [&](pair<int,int> p1, pair<int,int> p2) {
            return p1.second > p2.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        pq.push(make_pair(ball[0]*n+ball[1], 0));
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int x = curr.first/n, y = curr.first%n;
            if (curr.second > dists[x][y]) continue;
            if (x == hole[0] && y == hole[1]) return ways[x][y];
            
            for (int k = 0; k < dirs.size(); ++k) {
                auto dir = dirs[k];
                int i = x, j = y, count = 0;
                string trial = ways[x][y] + way[k];
                while (i+dir[0] >= 0 && i+dir[0] < m && j+dir[1] >= 0 && j+dir[1] < n && maze[i+dir[0]][j+dir[1]] == 0) {
                    i += dir[0]; j += dir[1]; ++count;
                    if (i == hole[0] && j == hole[1]) break;
                }
                if (count == 0) continue;
                
                if (dists[i][j] > dists[x][y] + count) {
                    dists[i][j] = dists[x][y] + count;
                    ways[i][j] = trial;
                    pq.push(make_pair(i*n+j, dists[i][j]));
                } else if (dists[i][j] == dists[x][y] + count) {
                    if (trial < ways[i][j]) ways[i][j] = trial;
                }
            }
        }
        
        return "impossible";
    }
};
