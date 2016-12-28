class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> solution(n, string(n, '.'));
        dfs(result, solution, 0, n);
        return result;
    }
    
private:
    void dfs(vector<vector<string>>& result, vector<string>& solution, int row, int n) {
        if (row == n) {
            result.emplace_back(solution);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (isValid(solution, row, col, n)) {
                solution[row][col] = 'Q';
                dfs(result, solution, row+1, n);
                solution[row][col] = '.';
            }
        }
    }
    
    bool isValid(vector<string>& solution, int row, int col, int n) {
        for (int i = 0; i != row; ++i)
            if (solution[i][col] == 'Q') return false;
        
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j)
            if (solution[i][j] == 'Q') return false;
        
        for (int i = row-1, j = col+1; i >= 0 && j < n; --i, ++j)
            if (solution[i][j] == 'Q') return false;
            
        return true;
    }
};
