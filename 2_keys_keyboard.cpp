class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        
        int dp[n+1] = {};
        dp[0] = 0; dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            for (int j = 2; j < i; ++j) {
                if (i%j == 0) {
                    dp[i] = min(dp[i], dp[j] + 1 + (i/j -1));
                }
            }
        }
        return dp[n];
    }
};
