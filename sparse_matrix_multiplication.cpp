class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = B.size(), p = B[0].size();
        vector<vector<int>> result(m, vector<int>(p, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j]) {
                    for (int t = 0; t < p; ++t) {
                        if(B[j][t]) result[i][t] += A[i][j] * B[j][t];
                    }
                }
            }
        }
        return result;
    }
};
