class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        
        int m = matrix.size(), n = matrix[0].size(), r_begin = 0, r_end = m-1, c_begin = 0, c_end = n-1;
        while (r_begin <= r_end && c_begin <= c_end) {
            for (int j = c_begin; j <= c_end; ++j) {
                result.emplace_back(matrix[r_begin][j]);
            }
            r_begin++;
            
            for (int i = r_begin; i <= r_end; ++i) {
                result.emplace_back(matrix[i][c_end]);
            }
            c_end--;
            
            if (r_begin <= r_end) {
                for (int j = c_end; j >= c_begin; --j) {
                    result.emplace_back(matrix[r_end][j]);
                }
            }
            r_end--;
            
            if (c_begin <= c_end) {
                for (int i = r_end; i >= r_begin; --i) {
                    result.emplace_back(matrix[i][c_begin]);
                }
            }
            c_begin++;
        }
        
        return result;
    }
};
