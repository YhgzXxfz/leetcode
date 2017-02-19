class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2) { return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second; };
        sort(points.begin(), points.end(), comp);
        
        int count = 0, arrow = INT_MIN;
        for (auto point : points) {
            if (arrow != INT_MIN && point.first <= arrow) continue;
            arrow = point.second;
            count++;
        }
        return count;
    }
};
