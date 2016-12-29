class Solution {
public:
    int numberOfPatterns(int m, int n) {
        return dfs(m, n, 0, 1, 1, 1, 1);
    }

private:
    int dfs(int m, int n, int used, int curr_x, int curr_y, int prev_x, int prev_y) {
        int number = m <= 0;
        if (!n) return 1;
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int x = prev_x+i, y = prev_y+j, used2 = used | (1 << (i*3 + j));
                if (used2 > used && (x&1 || y&1 || used2 & (1 << (x/2*3 + y/2))))
                    number += dfs(m-1, n-1, used2, prev_x, prev_y, i, j);
            }
        }
        return number;
    }
};
