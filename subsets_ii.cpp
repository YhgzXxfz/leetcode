class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        vector<int> solution;
        dfs(result, nums, solution, 0);
        return result;
    }

private: 
    void dfs(vector<vector<int>>& result, vector<int>& nums, vector<int>& solution, int start) {
        result.emplace_back(solution);
        if (start >= nums.size()) return ;
        
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || (i > start && nums[i] != nums[i-1])) {
                solution.push_back(nums[i]);
                dfs(result, nums, solution, i+1);
                solution.pop_back();
            }
        }
    }
};
