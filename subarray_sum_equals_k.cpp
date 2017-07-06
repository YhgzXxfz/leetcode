class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        mp[0].push_back(-1);
        int sum = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (mp.find(sum-k) != mp.end()) count += mp[sum-k].size();
            mp[sum].push_back(i);
        }
        return count;
    }
};
