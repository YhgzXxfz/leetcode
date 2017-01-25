// dfs
/*
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0, start = 0, curr = 0;
        dfs(nums, S, count, start, curr);
        return count;
    }

private:
    void dfs(vector<int>& nums, int S, int& count, int start, int curr) {
        if (start == nums.size()) {
            count += curr == S;
            return ;
        }
        
        dfs(nums, S, count, start+1, curr+nums[start]);
        dfs(nums, S, count, start+1, curr-nums[start]);
    }
};
*/

// dp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < S || (S+sum) &1 ? 0 : subsetSum(nums, (S+sum) >> 1);
    }

private:
    int subsetSum(vector<int>& nums, int target) {
        int dp[target+1] = {};
        dp[0] = 1;
        for (auto num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};
