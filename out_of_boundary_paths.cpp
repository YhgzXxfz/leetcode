// dfs + cache
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> cache(m, vector<vector<int>>(n, vector<int>(N+1,-1)));
        return dfs(m, n, N, i, j, cache);
    }

private:
    int dfs(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& cache) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 1;
        if (N == 0) return 0;
        
        if (cache[i][j][N] >= 0) return cache[i][j][N];
        cache[i][j][N] = ((dfs(m,n,N-1, i+1,j, cache)%M + dfs(m,n,N-1,i,j+1, cache)%M) %M
                          + (dfs(m,n,N-1,i-1,j, cache)%M + dfs(m,n,N-1, i,j-1, cache)%M)%M)%M ;
        return cache[i][j][N];
    }
    
    int M = 1e9+7;
};


// dp
class Solution {
public:
    int findPaths(int m, int n, int N, int x, int y) {
        int M = 1e9+7;
		vector<vector<int>> dp(m, vector<int>(n,0));
		dp[x][y] = 1;
		int count = 0;
		for (int moves = 1; moves <= N; ++moves) {
			auto temp = dp;
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i == m - 1) count = (count + dp[i][j]) % M;
                    if (j == n - 1) count = (count + dp[i][j]) % M;
                    if (i == 0) count = (count + dp[i][j]) % M;
                    if (j == 0) count = (count + dp[i][j]) % M;

                    temp[i][j] = (((i > 0 ? dp[i - 1][j] : 0) +(i < m - 1 ? dp[i + 1][j] : 0)) %M + 
                                ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % M) % M;
				}
			}
			dp = temp;
		}
		return count;
    }
};
