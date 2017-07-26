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
