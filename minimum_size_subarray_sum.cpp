class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int begin = 0, min_len = INT_MAX, sum = 0;
        
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            while (sum >= s) {
                min_len = min(min_len, i+1 - begin);
                sum -= nums[begin];
                ++begin;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};
