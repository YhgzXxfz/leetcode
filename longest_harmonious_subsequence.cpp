class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_map<int, int> mp;
        int max_count = 0;
        for (auto num : nums) {
            mp[num]++;
            
            if (mp.count(num-1)) max_count = max(max_count, mp[num]+mp[num-1]);
            if (mp.count(num+1)) max_count = max(max_count, mp[num]+mp[num+1]);
        }
        return max_count;
    }
};
