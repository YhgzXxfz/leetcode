class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        for (auto row : wall) {
            int sum = 0;
            for (int i = 0; i < row.size()-1; ++i) {
                sum += row[i];
                mp[sum]++;
            }
        }
        
        int max_same_len = 0;
        for (auto entry : mp) {
            max_same_len = max(max_same_len, entry.second);
        }
        return wall.size() - max_same_len;
    }
};
