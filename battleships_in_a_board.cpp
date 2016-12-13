class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        
        m = board.size(), n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool> (n, false));
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' && !visited[i][j]) {
                    ++count;
                    
                    queue<pair<int, int>> q;
                    q.push(make_pair(i,j));
                    while (!q.empty()) {
                        auto pos = q.front();
                        q.pop();
                        visited[pos.first][pos.second] = true;
                        for (auto& dir : directions) {
                            int x = pos.first+dir[0], y = pos.second+dir[1];
                            if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '.' || visited[x][y]) continue;
                            q.push(make_pair(x,y));
                        }
                    }
                }
            }
        }
        return count;
    }

private:
    int m, n;
    vector<vector<int> > directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
};
