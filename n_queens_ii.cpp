class Solution {
public:
    int totalNQueens(int n) {
        vector<string> solution(n, string(n, '.'));
        int count = 0;
        dfs(solution, 0, n, count);
        return count;
    }
    
private:
    void dfs(vector<string>& solution, int row, int n, int& count) {
        if (row == n) {
            ++count;
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (isValid(solution, row, col, n)) {
                solution[row][col] = 'Q';
                dfs(solution, row+1, n, count);
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
