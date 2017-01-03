class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), max_matrix_sum = INT_MIN;
        
        for (int c = 0; c < n; ++c) {
            vector<int> sums(m, 0);
            for (int j = c; j < n; ++j) {
                for (int i = 0; i < m; ++i) {
                    sums[i] += matrix[i][j];
                }
                
                set<int> cums;
                cums.insert(0);
                int cum = 0, max_col_sum = INT_MIN;
                for (int sum : sums) {
                    cum += sum;
                    auto it = cums.lower_bound(cum-k);
                    if (it != cums.end()) max_col_sum = max(max_col_sum, cum-*it);
                    cums.insert(cum);
                }
                max_matrix_sum = max(max_matrix_sum, max_col_sum);
            }
        }
        return max_matrix_sum;
    }
};
