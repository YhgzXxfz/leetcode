class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        int result, min_diff = INT_MAX;
        
        for (int i = 0; i < len-2; ++i) {
            if (i == 0 || i > 0 && nums[i] != nums[i-1]) {
                int left = i+1, right = len-1;
                while (left < right) {
                    int sum = nums[i]+nums[left]+nums[right];
                    if (sum == target) return target;
                    
                    int diff = abs(sum-target);
                    if (diff < min_diff) {
                        min_diff = diff;
                        result = sum;
                    }
                    
                    if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return result;
    }
};
