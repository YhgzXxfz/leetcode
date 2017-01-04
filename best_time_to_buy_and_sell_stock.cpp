class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, low = INT_MAX;
        for (auto& price : prices) {
            low = min(low, price);
            
            if (price > low) max_profit = max(max_profit, price-low);
        }
        return max_profit;
    }
};
