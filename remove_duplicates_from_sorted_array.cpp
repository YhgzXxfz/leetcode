class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int left = 0, i = 0;
        while (i < nums.size()) {
            if (nums[i] == nums[left]) i++;
            else {
                left++;
                nums[left] = nums[i];
                i++;
            }
        }
        return left+1;
    }
};
