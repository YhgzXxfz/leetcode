class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int>();
        
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = 0, d = 0;
        
        vector<vector<int>> dirs = {{-1,1}, {1,-1}};
        vector<int> result;
        for (int i = 0; i < m*n; ++i) {
            result.emplace_back(matrix[row][col]);
            row += dirs[d][0];
            col += dirs[d][1];
            
            if (row >= m) { row = m-1; col += 2; d = 1-d;}
            if (col >= n) { col = n-1; row += 2; d = 1-d;}
            if (row < 0)  { row = 0; d = 1-d;}
            if (col < 0)  { col = 0; d = 1-d;}
        }
        return result;
    }
};
