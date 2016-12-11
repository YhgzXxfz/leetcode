class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return;
        
        int left = 0, right = len-1, i = 0;
        while (i <= right) {
            if (nums[i] == 0) swap(nums[left++], nums[i++]);
            else if (nums[i] == 1) i++;
            else swap(nums[i], nums[right--]);
        }
    }
};
