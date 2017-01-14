class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        if (n == 0) return matrix;
        
        int r_begin = 0, r_end = n-1, c_begin = 0, c_end = n-1, num = 1;
        while (r_begin <= r_end && c_begin <= c_end) {
            for (int j = c_begin; j <= c_end; ++j) {
                matrix[r_begin][j] = num++;
            }
            r_begin++;
            
            for (int i = r_begin; i <= r_end; ++i) {
                matrix[i][c_end] = num++;
            }
            c_end--;
            
            for (int j = c_end; j >= c_begin; --j) {
                if (r_begin <= r_end) matrix[r_end][j] = num++;
            }
            r_end--;
            
            for (int i = r_end; i >= r_begin; --i) {
                if (c_begin <= c_end) matrix[i][c_begin] = num++;
            }
            c_begin++;
        }
        
        return matrix;
    }
};
