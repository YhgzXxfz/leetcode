class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        
        int max_len = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (mp.find(sum) == mp.end()) mp[sum] = i;
            if (mp.find(sum-k) != mp.end()) max_len = max(max_len, i-mp[sum-k]);
        }
        return max_len;
    }
};
