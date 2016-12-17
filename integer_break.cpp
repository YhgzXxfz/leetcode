class Solution {
public:
    int integerBreak(int n) {
        
        // 1 dp O(n^2)
        /*
        int dp[n+1];
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = 0;
            for (int j = 1; j < i ; ++j) {
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
        */
        
        // 2 math O(n)
        if (n == 2 || n == 3) return n-1;
        
        int result = 1;
        while (n > 4) {
            n -= 3;
            result *= 3;
        }
        return n*result;
    }
};
