class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp
        /*
        int dp[m+1][n+1] = {};
        dp[0][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
        */
        
        // math (m-1+n-1)!/((m-1)!(n-1)!)
        double result = 1;
        for (int i = 1; i <= m-1; i++) {
            result = result * (n-1+i) / i;
        }
        return (int)result;
    }
};
