class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) return ;
        
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!rooms[i][j]) q.push(make_pair(i,j));
            }
        }
        
        int depth = 1;
        while (!q.empty()) {
            int size = q.size(); // necessary for the queue size might change in the loop
            for (int k = 0; k < size; ++k) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                bfs(rooms, q, i+1, j, m, n, depth);
                bfs(rooms, q, i-1, j, m, n, depth);
                bfs(rooms, q, i, j+1, m, n, depth);
                bfs(rooms, q, i, j-1, m, n, depth);
            }
            
            depth++;
        }
    }

private:
    void bfs(vector<vector<int>>& rooms, queue<pair<int, int>>& q, int i, int j, int m, int n, int depth) {
        if (i >= 0 && i < m && j >= 0 && j < n && rooms[i][j] > depth) {
            q.push(make_pair(i,j));
            rooms[i][j] = depth;
        }
    }
};
