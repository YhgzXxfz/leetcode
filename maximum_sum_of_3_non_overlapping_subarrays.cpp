class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> result(3);
        if (nums.empty() || k == 0) return result;
        
        int len = nums.size();
        vector<int> cums(len+1);
        for (int i = 1; i <= len; ++i) {
            cums[i] = cums[i-1]+nums[i-1];
        }
        
        vector<int> left(len, 0), right(len, len-k);
        int sum = cums[k]-cums[0];
        for (int i = k; i < len; ++i) {
            if (cums[i+1]-cums[i+1-k] > sum) {
                sum = cums[i+1]-cums[i+1-k];
                left[i+1-k] = i+1-k;
            } else {
                left[i+1-k] = left[i-k];
            }
        }
        
        sum = cums[len]-cums[len-k];
        for (int i = len-1-k; i >= 0; --i) {
            if (cums[i+k]-cums[i] >= sum) {
                sum = cums[i+k]-cums[i];
                right[i] = i;
            } else {
                right[i] = right[i+1];
            }
        }
        
        int max_sum = 0;
        for (int i = k; i <= len-2*k; ++i) {
            int l = left[i-k], r = right[i+k];
            sum = cums[l+k]-cums[l] + cums[i+k]-cums[i] + cums[r+k]-cums[r];
            if (sum > max_sum) {
                max_sum = sum;
                result = {l, i, r};
            }
        }
        return result;
    }
};
