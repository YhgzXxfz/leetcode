class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int with_stock = 0, without_stock = INT_MIN;
        for (auto p : prices) {
            int temp = with_stock;
            with_stock = max(with_stock, without_stock+p);
            without_stock = max(without_stock, temp-p-fee);
        }
        return with_stock;
    }
};
