class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (nums[0] >= 0 || nums[len-1] <= 0) return nums[len-1]*nums[len-2]*nums[len-3];
        return max(nums[len-1]*nums[len-2]*nums[len-3], nums[0]*nums[1]*nums[len-1]);
    }
};
