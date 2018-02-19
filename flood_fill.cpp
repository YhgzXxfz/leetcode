class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int new_color) {
        int m = image.size(), n = image[0].size();
        int old_color = image[sr][sc];
        if (new_color == old_color) return image;
        
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int i = curr.first, j = curr.second;
            image[i][j] = new_color;
            for (auto dir : dirs) {
                int x = i+dir[0], y = j+dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (image[x][y] == old_color) {
                    q.push(make_pair(x, y));
                }
            }
        }
        return image;
    }
};
