class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return len;
        
        int flag = 0, count = 1;
        for (int i = 0; i < len-1; ++i) {
            if (nums[i+1] > nums[i] && (flag == -1 || flag == 0)) {
                ++count;
                flag = 1;
            } else if (nums[i+1] < nums[i] && (flag == 1 || flag == 0)) {
                ++count;
                flag = -1;
            }
        }
        
        return count;
    }
};
