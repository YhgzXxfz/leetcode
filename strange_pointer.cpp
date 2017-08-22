class Solution {
public:
    int strangePrinter(string s) {
        vector<vector<int>> cache(100, vector<int>(100));
        int len = s.size();
        return dfs(s, 0, len-1, cache);
    }

private:
    int dfs(string s, int left, int right, vector<vector<int>>& cache) {
        if (left > right) return 0;
        
        if (cache[left][right]) return cache[left][right];
        
        cache[left][right] = dfs(s, left, right-1, cache) +1;
        for (int i = left; i < right; ++i) {
            if (s[i] == s[right]) {
                cache[left][right] = min(cache[left][right], dfs(s, left, i, cache) + dfs(s, i+1, right-1, cache));
            }
        }
        return cache[left][right];
    }
};
