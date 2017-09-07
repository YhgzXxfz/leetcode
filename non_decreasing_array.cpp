class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return true;
        
        int modified = 0, prev = nums[0];
        for (int i = 1; i < len; ++i) {
            if (nums[i] < prev && modified++) return false;
            if (nums[i] < prev && i-2 >= 0 && nums[i-2] > nums[i]) continue;
            
            prev = nums[i];
        }
        return true;
    }
};
