class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> solution;
        dfs(nums, 0, solution, st);

        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }

private:
    void dfs(vector<int>& nums, int start, vector<int>& solution, set<vector<int>>& st) {
        if (solution.size() >= 2) st.insert(solution);
        if (start >= nums.size()) return ;
        
        for (int i = start; i < nums.size(); ++i) {
            if (!solution.empty() && solution.back() > nums[i]) continue;
            
            solution.emplace_back(nums[i]);
            dfs(nums, i+1, solution, st);
            solution.pop_back();
        }
    }
};
