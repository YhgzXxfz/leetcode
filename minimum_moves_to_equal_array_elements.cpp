class Solution {
public:
    int minMoves(vector<int>& nums) {
        /*
        int min = INT_MAX;
        
        for (auto& num : nums) {
            if (num < min) min = num;
        }
        
        int result = 0;
        for (auto& num : nums) {
            result += num-min;
        }
        return result;
        */
        
        int min = *min_element(nums.begin(), nums.end());
        return accumulate(nums.begin(), nums.end(), 0) - min*nums.size();
    }
};
