class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp
        vector<long> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for (auto coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
        
        // sort + dp
        /*
        vector<long> dp(amount+1, INT_MAX);
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto coin : coins) {
                if (coin > i) break;
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : (int)dp[amount];
        */
    }
};
