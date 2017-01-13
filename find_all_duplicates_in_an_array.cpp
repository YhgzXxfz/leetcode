class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int i = 0, len = nums.size();
        while (i < len) {
            if (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        for (i = 0; i < len; ++i) {
            if (nums[i] != i+1) result.emplace_back(nums[i]);
        }
        return result;
    }
};
