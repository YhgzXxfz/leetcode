class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i + len - 1 <= n; ++i) {
                int j = i + len - 1;
                int min_cost = INT_MAX;
                for (int k = i; k <= j; ++k) {
                    int cost = k + max(dp[i][k-1], dp[k+1][j]);
                    min_cost = min(cost, min_cost);
                }
                dp[i][j] = min_cost;
            }
        }
        return dp[1][n];
    }
};
