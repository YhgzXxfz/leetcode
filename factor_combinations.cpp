class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> solution;
        dfs(n, result, solution, 2);
        return result;
    }

private:
    void dfs(int n, vector<vector<int>>& result, vector<int>& solution, int start) {
        if (n <= 1) {
            if (solution.size() > 1) result.emplace_back(solution);
            return ;
        }
        
        for (int i = start; i <= n; ++i) {
            if (n%i == 0) {
                solution.emplace_back(i);
                dfs(n/i, result, solution, i);
                solution.pop_back();
            }
        }
    }
};
