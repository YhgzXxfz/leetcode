class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        
        int m = costs.size(), n = costs[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                costs[i][j] += min(costs[i-1][(j+1)%n], costs[i-1][(j+2)%n]);
            }
        }
        return *min_element(costs[m-1].begin(), costs[m-1].end());
    }
};
