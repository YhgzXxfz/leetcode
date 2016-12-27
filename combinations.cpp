class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> solution;
        vector<vector<int>> result;
        
        dfs(result, solution, 1, n, k);
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& result, vector<int>& solution, int start, int n, int k) {
        if (solution.size() == k) {
            result.emplace_back(solution);
            return;
        }
        
        for (int i = start; i <= n; ++i) {
            solution.emplace_back(i);
            dfs(result, solution, i+1, n, k);
            solution.pop_back();
        }
    }
};
