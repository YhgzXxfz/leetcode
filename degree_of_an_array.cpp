class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> mp;
        for (auto num : nums) {
            ++mp[num];
        }
        
        int elem, max_freq = 0;
        for (auto entry : mp) {
            if (max_freq < entry.second) {
                max_freq = entry.second;
                elem = entry.first;
            }
        }
        
        queue<int> q;
        for (auto entry : mp) {
            if (entry.second == max_freq) q.push(entry.first);
        }
        int min_len = len;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int left, right;
            for (int i = 0; i < len; ++i) {
                if (nums[i] == curr) {
                    left = i;
                    break;
                }
            }
            for (int i = len-1; i >= 0; --i) {
                if (nums[i] == curr) {
                    right = i;
                    break;
                }
            }
            min_len = min(min_len, right-left+1);
        }
        return min_len;
    }
};
