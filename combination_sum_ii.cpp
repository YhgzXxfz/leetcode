class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> solution;
        sort(candidates.begin(), candidates.end());
        
        dfs(result, solution, target, 0, candidates);
        return result;
    }

private:
    void dfs(vector<vector<int>>& result, vector<int>& solution, int gap, int start, vector<int>& nums) {
        if (gap == 0) {
            result.emplace_back(solution);
            return;
        }
        
        for (int i = start; i < nums.size(); ++i) {
            if (gap < nums[i]) return;
            
            if (i > start && nums[i] == nums[i-1]) continue;
            
            solution.emplace_back(nums[i]);
            dfs(result, solution, gap-nums[i], i+1, nums);
            solution.pop_back();
        }
    }
};
