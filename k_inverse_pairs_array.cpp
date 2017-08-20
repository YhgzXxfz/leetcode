class Solution {
public:
    int kInversePairs(int n, int k) {
        int M = 1e9+7;
        if (k > n*(n-1)/2 || k < 0) return 0;
        if (k == n*(n-1)/2 || k == 0) return 1;
        
        vector<vector<long>> dp(n+1, vector<long>(k+1));
        dp[2][0] = 1; dp[2][1] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= min(k, i*(i-1)/2); ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if (j >= i) dp[i][j] -= dp[i-1][j-i];
                dp[i][j] = (dp[i][j] + M) %M;
            }
        }
        return dp[n][k];
    }
};
