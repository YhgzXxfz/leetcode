class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long first_missing = 1, count = 0, i = 0;
        while (first_missing <= n) {
            if (i < nums.size() && first_missing >= nums[i]) {
                first_missing += nums[i];
                i++;
            } else {
                first_missing *= 2;
                count++;
            }
        }
        return count;
    }
};
