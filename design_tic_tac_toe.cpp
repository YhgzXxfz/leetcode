class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n):size(n) {
        rows.resize(n);
        cols.resize(n);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int val = player == 1 ? 1 : -1;
        rows[row] += val;
        cols[col] += val;
        if (row == col) diagonal += val;
        if (row+col == size-1) anti_diagonal += val;
        
        if (abs(rows[row]) == size || abs(cols[col]) == size || abs(diagonal) == size || abs(anti_diagonal) == size) 
            return player;
            
        return 0;
    }

private:
    int size, diagonal, anti_diagonal;
    vector<int> rows, cols;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
