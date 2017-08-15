class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty()) return 0;
        
        int m = picture.size(), n = picture[0].size();
        vector<int> cols(n, 0);
        unordered_map<string, int> mp;
        for (int i = 0; i < m; ++i) {
            string key = scanRow(picture, i, N, cols);
            if (!key.empty()) mp[key]++;
        }
        
        int result = 0;
        for (auto entry : mp) {
            if (entry.second == N) {
                for (int j = 0; j < n; ++j) {
                    if (entry.first[j] == 'B' && cols[j] == N) result += N;
                }
            }
        }
        return result;
    }

private:
    string scanRow(vector<vector<char>>& picture, int row, int N, vector<int>& cols) {
        int n = picture[0].size(), black = 0;
        string key = "";
        for (int j = 0; j < n; ++j) {
            if (picture[row][j] == 'B') {
                cols[j]++;
                black++;
            }
            key += picture[row][j];
        }
        return black == N ? key : "";
    }
};
