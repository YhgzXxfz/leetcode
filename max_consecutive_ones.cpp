class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // 1
        /*
        int max_len = 0, begin = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                begin = i+1;
            } else {
                max_len = max(max_len, i-begin+1);
            }
        }
        return max_len;
        */
        
        // 2
        int max_len = 0, curr = 0;
        for (auto& num : nums) {
            curr = num == 0 ? 0 : curr+1;
            
            max_len = max(max_len, curr);
        }
        return max_len;
    }
};
