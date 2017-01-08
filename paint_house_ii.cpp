class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        
        int m = costs.size(), n = costs[0].size(), min1 = 0, min2 = 0;
        int dp[n] = {};
        for (int i = 0; i < m; ++i) {
            int t1 = min1, t2 = min2;
            min1 = min2 = INT_MAX;
            for (int j = 0; j < n; ++j) {
                dp[j] = costs[i][j] + (dp[j] == t1 ? t2 : t1);
                
                if (min1 <= dp[j]) min2 = min(min2, dp[j]);
                else {
                    min2 = min1;
                    min1 = dp[j];
                }
            }
        }
        return min1;
    }
};
