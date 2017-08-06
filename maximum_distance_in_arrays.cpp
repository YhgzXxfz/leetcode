// t-O(N^2), TLE
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max_dist = 0;
        for (auto array : arrays) {
            for (int i = 0; i < arrays.size(); ++i) {
                if (arrays[i] == array) continue;
                int len = arrays[i].size();
                max_dist = max(max_dist, max(abs(*array.begin() - arrays[i][len-1]), abs(*prev(array.end()) - arrays[i][0])));
            }
        }
        return max_dist;
    }
};

// t-O(N)
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_val = arrays[0][0], max_val = arrays[0].back(), max_dist = 0;
        for (int i = 1; i < arrays.size(); ++i) {
            int curr_min = arrays[i][0], curr_max = arrays[i].back();
            max_dist = max(max_dist, max(abs(curr_max - min_val), abs(max_val - curr_min)));
            
            min_val = min(min_val, curr_min);
            max_val = max(max_val, curr_max);
        }
        return max_dist;
    }
};
