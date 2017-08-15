class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if (picture.empty()) return 0;
        
        int m = picture.size(), n = picture[0].size();
        vector<int> rows(m, 0), cols(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        return min(count(rows.begin(), rows.end(), 1), count(cols.begin(), cols.end(), 1));
    }
};
