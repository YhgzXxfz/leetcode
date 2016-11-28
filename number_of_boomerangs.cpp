class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int len = points.size(), result = 0;
        
        for (int i = 0; i < len; ++i) {
            unordered_map<long, int> mp;
            for (int j = 0; j < len; ++j) {
                if (j == i) continue;
                
                int distance = pow(points[i].first-points[j].first, 2) + pow(points[i].second-points[j].second, 2);
                mp[distance]++;
            }
            
            for (auto& entry : mp) {
                if (entry.second >= 2) result += entry.second * (entry.second-1);
            }
        }
        return result;
    }
};
