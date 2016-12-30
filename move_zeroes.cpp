class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0, len = nums.size();
        // move all the nonzero elements advance
        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < len; j++) {
            nums[j] = 0;
        }
    }
};
