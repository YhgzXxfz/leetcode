class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index, elem = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > elem) {
                elem = nums[i];
                index = i;
            }
        }
        
        for (auto num : nums) {
            if (num == elem) continue;
            if (elem < (num << 1)) return -1;
        }
        return index;
    }
};
