class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int reach = 1;
        for (int i = 0 ; i < reach && reach < len; ++i) {
            reach = max (reach, nums[i]+i+1);
        }
        return reach >= len;
    }
};
