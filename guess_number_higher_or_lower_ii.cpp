class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> cache(n+1, vector<int>(n+1));
        return dfs(cache, 1, n);
    }
    
private:
    int dfs(vector<vector<int>>& cache, int begin, int end) {
        if (begin >= end) return 0;
        if (cache[begin][end]) return cache[begin][end];
        
        int cost = INT_MAX;
        // min-max: minimize the maximum loss
        for (int x = begin; x <= end; ++x) {
            int temp = x + max(dfs(cache, begin, x-1), dfs(cache, x+1, end));
            cost = min(cost, temp);
        }
        cache[begin][end] = cost;
        return cost;
    }
};
