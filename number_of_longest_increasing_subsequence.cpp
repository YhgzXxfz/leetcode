class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int len = nums.size();
        vector<int> dp(len, 1), count(len, 1);
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[i] == dp[j]+1) count[i] += count[j];
                    else if (dp[i] < dp[j]+1) {
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }
                }
            }
        }
        
        int max_len = *max_element(dp.begin(), dp.end());
        int result = 0;
        for (int i = 0; i < len; ++i) {
            if (dp[i] == max_len) result += count[i];
        }
        return result;
    }
};
