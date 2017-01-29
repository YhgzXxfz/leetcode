class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        if (k > len/2) return quickSolve(prices);
        return dpSolve(prices, k);
    }

private:
    int quickSolve(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            profit += max(0, prices[i]-prices[i-1]);
        }
        return profit;
    }
    
    int dpSolve(vector<int>& prices, int k) {
        vector<int> balance(k+1, INT_MIN), profit(k+1);
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                balance[j] = max(balance[j], profit[j-1]-prices[i]);
                profit[j] = max(profit[j], balance[j]+prices[i]);
            }
        }
        return profit[k];
    }
};

