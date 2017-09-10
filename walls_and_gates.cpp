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
        
	vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        int depth = 1;
        while (!q.empty()) {
            int size = q.size(); // necessary for the queue size might change in the loop
            for (int k = 0; k < size; ++k) {
                auto curr = q.front();
                q.pop();
		for (auto dir : dirs) {
			int x = curr.first+dir[0], y = curr.second+dir[1];
			if (x >= 0 && x < m && y >= 0 && y < n && romms[x][y] > depth) {
				q.push(make_pair(x,y));
				rooms[x][y] = depth;
			}
		}
            }
            
            ++depth;
        }
    }
};
