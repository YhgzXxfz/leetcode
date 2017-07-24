class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return to_string(nums[0]);
        if (len == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        
        string result = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for (int i = 2; i < len; ++i) result += "/" + to_string(nums[i]);
        result += ")";
        return result;
    }
};
