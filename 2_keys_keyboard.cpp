// dp, t-O(N)
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

// math, t-O(logN)
class Solution {
public:
    int minSteps(int n) {
        int s = 0;
        for (int d = 2; d <= n; d++) {
            while (n % d == 0) {
                s += d;
                n /= d;
            }
        }
        return s;
    }
};
