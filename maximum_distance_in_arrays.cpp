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
