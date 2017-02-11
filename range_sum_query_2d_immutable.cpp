class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();
        vector<vector<int>> grid(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                grid[i][j] = grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1]+matrix[i-1][j-1];
            }
        }
        data = grid;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return data[row2+1][col2+1] - data[row2+1][col1] - data[row1][col2+1] + data[row1][col1];
    }

private:
    vector<vector<int>> data;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
