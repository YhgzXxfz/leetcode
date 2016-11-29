class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        
        int max_path = INT_MIN, len = 1;
        vector<vector<int>> cache(row, vector<int> (col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                len = LongestIncreasingPath(matrix, i, j, cache);
                max_path = max(max_path, len);
            }
        }
        return max_path;
    }
    
    int LongestIncreasingPath(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& cache) {
        int row = matrix.size(), col = matrix[0].size();
        if (i < 0 || i >= row || j < 0 || j >= col) return 0;
        if (cache[i][j] != 0) return cache[i][j];
        
        int curr = matrix[i][j], max_path = 1;
        if (i > 0 && matrix[i-1][j] > curr) {
            int len = 1+LongestIncreasingPath(matrix, i-1, j, cache);
            max_path = max(max_path, len);
        }
        
        if (i < row-1 && matrix[i+1][j] > curr) {
            int len = 1+LongestIncreasingPath(matrix, i+1, j, cache);
            max_path = max(max_path, len);
        }
        
        if (j > 0 && matrix[i][j-1] > curr) {
            int len = 1+LongestIncreasingPath(matrix, i, j-1, cache);
            max_path = max(max_path, len);
        }
        
        if (j < col-1 && matrix[i][j+1] > curr) {
            int len = 1+LongestIncreasingPath(matrix, i, j+1, cache);
            max_path = max(max_path, len);
        }
        
        cache[i][j] = max_path;
        return max_path;
    }
};
