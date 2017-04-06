class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result, doubled_nums(nums);
        doubled_nums.insert(doubled_nums.end(), doubled_nums.begin(), doubled_nums.end());
        
        int len = nums.size();
        bool found = false;
        for (int i = 0; i < len; ++i) {
            found = false;
            for (int j = i+1; j < len+i+1; ++j) {
                if (doubled_nums[j] > nums[i]) {
                    found = true;
                    result.emplace_back(doubled_nums[j]);
                    break;
                }
            }
            if (!found) result.emplace_back(-1);
        }
        return result;
    }
};
