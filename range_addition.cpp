class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> nums(length+1,0);
        for (auto& update : updates) {
            nums[update[0]] += update[2];
            nums[update[1]+1] -= update[2];
        }
        
        int sum = 0;
        vector<int> result;
        for (int i = 0; i < length; ++i) {
            sum += nums[i];
            result.emplace_back(sum);
        }
        return result;
    }
};
