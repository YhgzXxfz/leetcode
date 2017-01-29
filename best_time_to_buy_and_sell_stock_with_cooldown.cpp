class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size() < 2) return 0;

		int b0 = -prices[0], s0 = 0, b1 = b0, b2 = 0, s1 = 0, s2 = 0;
		for (auto price : prices) {
			b2 = max(b1, s0-price);
			s2 = max(s1, b1+price);

			b1 = b2; s0 = s1; s1 = s2;
		}
		return s2;
    }
};
//
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell = 0, prev_buy = 0, prev_sell = 0;
        for (auto price : prices) {
            prev_buy = buy;
            buy = max(buy, prev_sell - price);
            prev_sell = sell;
            sell = max(sell, prev_buy + price);
        }
        return sell;
    }
};
*/
