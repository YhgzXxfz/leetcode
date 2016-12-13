class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if (len <= 1) return len;
        
        vector<int> nums(len, 1);
        for (int i = 1; i < len; ++i) {
            if (ratings[i] > ratings[i-1]) nums[i] = nums[i-1]+1;
        }
        
        for (int i = len-1; i > 0; --i) {
            if (ratings[i-1] > ratings[i]) nums[i-1] = max(nums[i-1], nums[i]+1);
        }
        
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
