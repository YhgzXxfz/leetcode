class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> result;
        if (M.empty()) return result;
        
        int m = M.size(), n = M[0].size();
        result.resize(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = computeNeighbors(M, i, j);
            }
        }
        return result;
    }

private:
    int computeNeighbors(vector<vector<int>>& M, int x, int y) {
        int m = M.size(), n = M[0].size(), sum = 0, count = 0;
        for (int i = max(x-1, 0); i <= min(x+1, m-1); ++i) {
            for (int j = max(y-1, 0); j <= min(y+1, n-1); ++j) {
                sum += M[i][j];
                ++count;
            }
        }
        return sum/count;
    }
};
