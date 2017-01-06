class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 1) return 0;
        
        int valley = prices[0], peak = prices[len-1], max_profit = 0;
        vector<int> f(len, 0), g(len, 0);
        
        for (int i = 1 ; i < len; ++i) {
            valley = min(valley, prices[i]);
            f[i] = max(f[i-1], prices[i] - valley);
        }
        
        for (int i = len-2; i >= 0; --i) {
            peak = max(peak, prices[i]);
            g[i] = max(g[i], peak - prices[i]);
        }
        
        for (int i = 0; i < len; ++i) {
            max_profit = max(max_profit, f[i]+g[i]);
        }
        return max_profit;
    }
};
