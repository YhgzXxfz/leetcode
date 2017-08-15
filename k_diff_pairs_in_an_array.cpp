class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1 || k < 0) return 0;
        
        unordered_map<int, unordered_set<int>> mp;
        sort(nums.begin(), nums.end());
        int begin = 0, i = 1;
        while (i < len) {
            if (begin == i) {
                ++i;
                continue;
            }
            
            int diff = nums[i]-nums[begin];
            if (diff == k) {
                mp[nums[begin]].insert(nums[i]);
                ++i;
            }
            else if (diff < k) ++i;
            else ++begin;
        }
        
        int count = 0;
        for (auto entry : mp) {
            if (!entry.second.empty()) count += entry.second.size();
        }
        return count;
    }
};
