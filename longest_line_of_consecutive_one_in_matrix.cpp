class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        
        matrix = M;
        m = matrix.size(), n = matrix[0].size();
        int max_len = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    exploreHorizontal(i, j, max_len);
                    exploreVertical(i, j, max_len);
                    exploreDiagonal(i, j, max_len);
                    exploreAntiDiagonal(i, j, max_len);
                }
            }
        }
        return max_len;
    }

private:
    void exploreHorizontal(int i, int j, int& max_len) {
        int row = 0;
        while (i >= 0 && matrix[i][j] == 1) { row++; i--; }
        max_len = max(max_len, row);
    }
    
    void exploreVertical(int i, int j, int& max_len) {
        int col = 0;
        while (j >= 0 && matrix[i][j] == 1) { col++; j--; }
        max_len = max(max_len, col);
    }
    
    void exploreDiagonal(int i, int j, int& max_len) {
        int diag = 0; 
        while (i >= 0 && j >= 0 && matrix[i][j] == 1) { diag++; i--; j--; }
        max_len = max(max_len, diag);
    }
    
    void exploreAntiDiagonal(int i, int j, int& max_len) {
        int anti_diag = 0;
        while (i >= 0 && j < n && matrix[i][j] == 1) { anti_diag++; i--; j++; }
        max_len = max(max_len, anti_diag);
    }
    
    vector<vector<int>> matrix;
    int m, n;
};
