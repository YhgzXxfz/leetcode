// dfs + cache
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> dict(26, vector<int>());
        for (int i = 0; i < ring.size(); ++i) {
            dict[ring[i]-'a'].push_back(i);
        }
        vector<vector<int>> cache(ring.size(), vector<int>(key.size()));
        return dfs(ring, key, 0, 0, dict, cache);
    }

private:
    int dfs(string& ring, string& key, int p1, int p2, vector<vector<int>>& dict, vector<vector<int>>& cache) {
        if (p2 == key.size()) return 0;
        if (cache[p1][p2]) return cache[p1][p2];
        
        int count = INT_MAX, len = ring.size();
        for (auto pos : dict[key[p2]-'a']) {
            int dist = abs(pos-p1);
            count = min(count, min(dist, len-dist) + dfs(ring, key, pos, p2+1, dict, cache));
        }
        cache[p1][p2] = count+1;
        return cache[p1][p2];
    }
};


// dp
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int r = ring.size(), k = key.size();
        vector<vector<int>> dict(26, vector<int>());
        for (int i = 0; i < ring.size(); ++i) {
            dict[ring[i]-'a'].push_back(i);
        }
        vector<vector<int>> dp(k+1, vector<int>(r, INT_MAX));
        dp[k].assign(r, 0);
        for (int i = k-1; i >= 0; --i) {
            for (int j = 0; j < r; ++j) {
                for (auto pos : dict[key[i]-'a']) {
                    int dist = abs(pos-j);
                    dp[i][j] = min(dp[i][j], min(dist, r-dist) + dp[i+1][pos]);
                }
            }
        }
        return dp[0][0]+k;
    }
};
