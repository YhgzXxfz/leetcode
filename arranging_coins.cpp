class Solution {
public:
    int arrangeCoins(int n) {
        return sqrt(2 * (long)n + 1 / 4.0) - 1 / 2.0;
    }
};
