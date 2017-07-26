class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        
        auto copy = nums;
        sort(nums.begin(), nums.end());
        int left = 0, right = len-1;
        while (left < len && nums[left] == copy[left]) left++;
        while (right >= 0 && nums[right] == copy[right]) right--;
        return right > left ? right-left+1 : 0;
    }
};
