class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // 1
        if (matrix.empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        int max_len = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0]-'0';
            max_len = max(max_len, dp[i][0]);
        }
        
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j]-'0';
            max_len = max(max_len, dp[0][j]);
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) +1;
                    max_len = max(max_len, dp[i][j]);
                }
            }
        }
        return max_len * max_len;
        
        // 2
        /*
        if (matrix.empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        
        vector<int> prev (m, 0), curr (m, 0);
        int max_len = 0;
        
        for (int i = 0; i < m; ++i) {
            prev[i] = matrix[i][0] - '0';
            max_len = max(max_len, prev[i]);
        }
        
        for (int j = 1; j < n; ++j) {
            curr[0] = matrix[0][j] - '0';
            max_len = max(max_len, curr[0]);
            for (int i = 1; i < m; ++i) {
                if (matrix[i][j] == '1') {
                    curr[i] = min(curr[i-1], min(prev[i-1], prev[i])) +1;
                    max_len = max(max_len, curr[i]);
                }
            }
            swap (prev, curr);
            fill(curr.begin(), curr.end(), 0);
        }
        
        return max_len * max_len;
        */
    }
};
