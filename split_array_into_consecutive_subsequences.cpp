class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> mp, tail;
        for (auto num : nums) mp[num]++;
        
        for (auto num : nums) {
            if (mp[num] == 0) continue;
            else if (tail[num] > 0) {
                tail[num]--;
                tail[num+1]++;
            } else if (mp[num+1] > 0 && mp[num+2] > 0) {
                mp[num+1]--;
                mp[num+2]--;
                tail[num+3]++;
            } else {
                return false;
            }
            mp[num]--;
        }
        return true;
    }
};
