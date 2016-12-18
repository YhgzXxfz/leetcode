class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int count = 0;
        for (int len = low.size(); len <= high.size(); ++len) {
            string c(len, '\0');
            dfs(low, high, c, count, 0, len-1);
        }
        return count;
    }
    
private:
    void dfs(string low, string high, string c, int& count, int left, int right) {
        if (left > right) {
            if (c.size() == low.size() && c<low || c.size() == high.size() && c > high) return;
            count++;
            return;
        }
        for (auto& p : pairs) {
            c[left] = p[0];
            c[right] = p[1];
            if (c.size() != 1 && c[0] == '0') continue;
            if (left == right && p[0] != p[1]) continue;
            dfs(low, high, c, count, left+1, right-1);
        }
    }
    
    vector<vector<char>> pairs = {{'0','0'},{'1','1'},{'8','8'},{'9','6'},{'6','9'}};
};
