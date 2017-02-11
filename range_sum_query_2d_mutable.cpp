class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        mx = matrix;
        int m = matrix.size();
        int n = m == 0 ? 0 : matrix[0].size();
        
        if (m == 0 || n == 0) return;
        
        row_sums = vector<vector<int>>(m, vector<int>(n+1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                row_sums[i][j] = matrix[i][j-1] + row_sums[i][j-1];
            }
        }
    }

    void update(int row, int col, int val) {
        for (int j = col+1; j <= mx[0].size(); ++j) {
            row_sums[row][j] += val-mx[row][col];
        }
        mx[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            sum += row_sums[i][col2+1]-row_sums[i][col1];
        }
        return sum;
    }

private:
    vector<vector<int>> mx, row_sums;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
