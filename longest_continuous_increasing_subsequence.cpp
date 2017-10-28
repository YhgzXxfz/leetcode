class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int max_len = 0, curr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] > nums[i-1]) ++curr;
            else curr = 1;
            
            max_len = max(max_len, curr);
        }
        return max_len;
    }
};
