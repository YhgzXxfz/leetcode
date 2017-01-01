class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return len;
        
        int count = 1, pos = 1;
        for (int i = 1; i < len; ++i) {
            if (nums[i] != nums[i-1]) {
                count = 1;
                nums[pos++] = nums[i];
            } else if (count < 2) {
                ++count;
                nums[pos++] = nums[i];
            }
        }
        return pos;
    }
};
