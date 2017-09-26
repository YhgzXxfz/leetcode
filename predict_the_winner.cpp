// dp
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
    	int len = nums.size();
	vector<vector<int>> dp(len+1, vector<int>(len,0));
	for (int i = len; i >= 0; --i) {
		for (int j = i+1; j < len; ++j) {
			int take_begin = nums[i] - dp[i+1][j];
			int take_end = nums[j] - dp[i][j-1];
			dp[i][j] = max(take_begin, take_end);
		}
	}
	return dp[0][len-1] >= 0;
    }
};


// dfs + cache
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

// dfs
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
