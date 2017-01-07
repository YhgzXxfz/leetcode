// bit manipulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum &1) return false;
        bitset<10001> bt(1);
        for (auto num : nums) {
            bt |= bt << num;
        }
        return bt[sum>>1];
    }
};

// dp
/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum>>1;
        if (sum &1) return false;
        
        int dp[target+1] = {};
        dp[0] = 1;
        for (auto num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[target];
    }
};
*/

// backtrack
/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        return (sum & 1) ? false : dfs(nums, 0, sum/2);
    }
    
private:
    bool dfs(vector<int>& nums, int start, int sum) {
        if (sum == 0) return true;
        if (sum < 0) return false;
        
        for (int i = start; i < nums.size(); ++i) {
            if (dfs(nums, i+1, sum-nums[i])) return true;
        }
        return false;
    }
};
*/
