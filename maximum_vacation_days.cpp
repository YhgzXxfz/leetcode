class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        N = days.size(); K = days[0].size();
        vector<vector<int>> cache(N, vector<int>(K, 0));
        return dfs(flights, days, 0, 0, cache);
    }

private:
    int dfs(vector<vector<int>>& flights, vector<vector<int>>& days, int city, int week, vector<vector<int>>& cache) {
        if (week == K) return 0;
        
        if (cache[city][week]) return cache[city][week];
        
        int max_count = 0;
        for (int i = 0; i < N; ++i) {
            if (flights[city][i] == 1 || i == city) {
                int count = days[i][week] + dfs(flights, days, i, week+1, cache);
                max_count = max(max_count, count);
            }
        }
        cache[city][week] = max_count;
        return max_count;
    }
    
    int N, K;
};
