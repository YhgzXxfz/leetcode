class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return ;
        
        auto neighbors = constructNeighbors(board);
        update(board, neighbors);
    }

private:
    vector<vector<int>> constructNeighbors(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> neighbors(m, vector<int>(n));
	for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                neighbors[i][j] = computeNeighbors(board, i, j);
            }
        }
	return neighbors;
    }
    
    int computeNeighbors(vector<vector<int>>& board, int row, int col) {
        int sum = 0, m = board.size(), n = board[0].size();
        for (int i = max(0, row-1); i <= min(m-1, row+1); ++i) {
            for (int j = max(0, col-1); j <= min(n-1, col+1); ++j) {
                sum += board[i][j];
            }
        }
	sum -= board[row][col];
        return sum;
    }
    
    void update(vector<vector<int>>& board, vector<vector<int>>& neighbors) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 1 && (neighbors[i][j] < 2 || neighbors[i][j] > 3)) board[i][j] = 0;
                if (board[i][j] == 0 && neighbors[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};
