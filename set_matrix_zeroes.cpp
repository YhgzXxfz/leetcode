// m-O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return ;
        
        int m = matrix.size(), n = matrix[0].size();
        bool fr = false, fc = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    if (i == 0) fr = true;
                    if (j == 0) fc = true;
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        
        if (fr) {
            for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        }
        if (fc) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};

// m-O(M+N)
/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return ;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row(m,0), col(n,0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) row[i] = col[j] = 1;
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] || col[j]) matrix[i][j] = 0;
            }
        }
    }
};
*/
