// dp
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() &1 == 0) return true;
        
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(len, -1));
        int curr = utill(nums, dp, 0, len-1);
        return 2*curr >= accumulate(nums.begin(), nums.end(), 0);
    }

private:
    int utill(vector<int>& nums, vector<vector<int>>& dp, int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int a = nums[i] + min(utill(nums, dp, i+1, j-1), utill(nums, dp, i+2, j));
        int b = nums[j] + min(utill(nums, dp, i, j-2), utill(nums, dp, i+1, j-1));
        dp[i][j] = max(a,b);
        
        return dp[i][j];
    }
};

// dfs + cache
/*
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        unordered_map<int, int> cache;
        return dfs(nums, 0, nums.size()-1, cache) >= 0;
    }

private:
    int dfs(vector<int>& nums, int begin, int end, unordered_map<int, int>& cache) {
        int len = nums.size(), index = begin*len+end;
        if (cache.find(index) != cache.end()) return cache[index];
        
        cache[index] = begin == end ? nums[begin] : max(nums[end]-dfs(nums, begin, end-1, cache), nums[begin]-dfs(nums, begin+1, end, cache));
        return cache[index];
    }
};
*/

// dfs
/*
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1) >= 0;
    }

private:
    int dfs(vector<int>& nums, int begin, int end) {
        return begin == end ? nums[begin] : max(nums[end]-dfs(nums, begin, end-1), nums[begin]-dfs(nums, begin+1, end));
    }
};
*/
