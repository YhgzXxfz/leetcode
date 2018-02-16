class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // start from left edge
        for (int i = m-1; i >= 0; --i) {
            int target = matrix[i][0];
            for (int row = i, col = 0; row < m && col < n; ++row, ++col) {
                if (matrix[row][col] != target) return false;
            }
        }
        
        // start from top edge
        for (int j = 0; j < n; ++j) {
            int target = matrix[0][j];
            for (int row = 0, col = j; row < m && col < n; ++row, ++col) {
                if (matrix[row][col] != target) return false;
            }
        }
        return true;
    }
};
