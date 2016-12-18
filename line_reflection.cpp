class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int max_x = INT_MIN, min_x = INT_MAX;
        unordered_set<string> st;
        for (auto& point : points) {
            max_x = max(max_x, point.first);
            min_x = min(min_x, point.first);
            st.insert(to_string(point.first)+"a"+to_string(point.second));
        }
        
        int sum = max_x+min_x;
        for (auto& point : points) {
            string opposite = to_string(sum-point.first)+"a"+to_string(point.second);
            if (!st.count(opposite)) return false;
        }
        return true;
    }
};
