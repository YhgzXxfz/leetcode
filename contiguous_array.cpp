class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_len = 0, ones = 0, zeroes = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) zeroes++;
            else ones++;
            
            if (mp.find(zeroes-ones) != mp.end()) max_len = max(max_len, i-mp[zeroes-ones]);
            else mp[zeroes-ones] = i;
        }
        return max_len;
    }
};
