class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        if (len == 2) return abs(nums[1]-nums[0]);
        
        sort(nums.begin(), nums.end());
        int mid = nums[len/2], sum = 0;
        for (auto num : nums) {
            sum += abs(num-mid);
        }
        return sum;
    }
};
