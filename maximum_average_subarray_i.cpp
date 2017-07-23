class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        if (k > len) return 0;

		int max_sum = accumulate(nums.begin(), nums.begin()+k, 0), sum = max_sum;

		for (int i = k; i < len; ++i) {
			max_sum = max(max_sum, sum += nums[i]-nums[i-k]);
		}
		return (double)max_sum / k;
    }
};
