class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = 0, last = 0, count = 0;
        int len = nums.size();
        
        for (int i = 0; i < len; ++i) {
            if (i > last) {
                last = curr;
                ++count;
            }
            curr = max(curr, nums[i]+i);
        }
        return count;
    }
};
