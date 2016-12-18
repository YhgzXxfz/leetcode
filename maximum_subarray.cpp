class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int curr_sum = 0, max_sum = nums[0];
        for (auto& num : nums) {
            curr_sum += num;
            if (curr_sum > max_sum) max_sum = curr_sum;
            if (curr_sum < 0) curr_sum = 0;
        }
        return max_sum;
    }
};
