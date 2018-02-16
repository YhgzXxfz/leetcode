class Solution {
public:
    int minCostClimbingStairs(vector<int>& costs) {
        int f1 = 0, f2 = 0;
        for (int i = costs.size() - 1; i >= 0; --i) {
            int f0 = costs[i] + min(f1, f2);
            f2 = f1;
            f1 = f0;
        }
        return min(f1, f2);
    }
};
