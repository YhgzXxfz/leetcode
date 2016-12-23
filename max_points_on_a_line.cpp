/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.empty()) return 0;
        
        int max_point = 0;
        for (int i = 0; i < points.size(); i++) {
            int same_point = 1;
            unordered_map<double, int> mp;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    same_point++;
                } else if (points[i].x == points[j].x) {
                    mp[INT_MAX]++;
                } else {
                    double slope = double(points[i].y - points[j].y) / double(points[i].x - points[j].x);
                    mp[slope]++;
                }
            }
            int curr_max = 0;
            for (auto& entry : mp){
                curr_max = max(curr_max, entry.second);
            }
            curr_max += same_point;
            max_point = max(max_point, curr_max);
        }
        return max_point;
    }
};
