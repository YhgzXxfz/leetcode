class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> solution;
        
        dfs(result, solution, 1, k, n);
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& result, vector<int>& solution, int start, int k, int gap) {
        if (solution.size() == k && gap == 0) {
            result.emplace_back(solution);
            return;
        }
        
        for (int i = start; i <= 9; ++i) {
            solution.push_back(i);
            dfs(result, solution, i+1, k, gap-i);
            solution.pop_back();
        }
    }
};
