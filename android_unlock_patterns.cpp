class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10, vector<int>(10, 0));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
        
        vector<int> visited(10, 0);
        int result = 0;
        for (int i = m; i <= n; ++i) {
            result += dfs(visited, skip, 1, i-1)*4;
            result += dfs(visited, skip, 2, i-1)*4;
            result += dfs(visited, skip, 5, i-1);
        }
        return result;
    }
    
private:
    int dfs(vector<int>& visited, vector<vector<int>>& skip, int curr, int remain) {
        if (remain < 0) return 0;
        if (remain == 0) return 1;
        
        visited[curr] = 1;
        int result = 0;
        for (int i = 1; i <= 9; ++i) {
            if (!visited[i] && (skip[curr][i] == 0 || visited[skip[curr][i]])) result += dfs(visited, skip, i, remain-1);
        }
        visited[curr] = 0;
        return result;
    }
};
