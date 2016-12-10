class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> solution;
        dfs(nums, result, solution, 0);
        return result;
    }

private:
    void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& solution, int start) {
        result.emplace_back(solution);
        if (solution.size() >= nums.size()) return;
        
        for (int i = start; i < nums.size(); ++i) {
            solution.emplace_back(nums[i]);
            dfs(nums, result, solution, i+1);
            solution.pop_back();
        }
    }
};
