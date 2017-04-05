class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        update(board, x, y, visited);
        return board;
    }
    
private:
    void update(vector<vector<char>>& board, int x, int y, vector<vector<int>>& visited) {
        int m = board.size(), n = board[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n) return ;
        if (visited[x][y]) return ;
        
        visited[x][y] = true;
        int mines = findMinesInNeighbor(board, x, y);
        if (mines) {
            board[x][y] = '0'+mines;
        } else {
            board[x][y] = 'B';
            for (int i = max(x-1, 0); i <= min(x+1, m-1); ++i) {
                for (int j = max(y-1, 0); j <= min(y+1, n-1); ++j) {
                    update(board, i, j, visited);
                }
            }
        }
    }
    
    int findMinesInNeighbor(vector<vector<char>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        
        int sum = 0;
        for (int i = max(x-1, 0); i <= min(x+1, m-1); ++i) {
            for (int j = max(y-1, 0); j <= min(y+1, n-1); ++j) {
                sum += board[i][j] == 'M';
            }
        }
        return sum;
    }
    
};
