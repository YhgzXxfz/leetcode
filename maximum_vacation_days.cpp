// dfs + cache
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


// dp 2D
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
	if (days.empty()) return 0;

        int N = days.size(), K = days[0].size();
        int dp[N][K+1] = {};
        for (int week = K-1; week >= 0; --week) {
            for (int city = 0; city < N; ++city) {
                dp[city][week] = days[city][week] + dp[city][week+1];
                for (int i = 0; i < N; ++i) {
                    if (flights[city][i] == 1) {
                        dp[city][week] = max(dp[city][week], days[i][week] + dp[i][week+1]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
