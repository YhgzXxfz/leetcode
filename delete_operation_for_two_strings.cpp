// dp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1));
        for (int i = 0; i <= len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else dp[i][j] = word1[i-1] == word2[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int val = dp[len1][len2];
        return len1 - val + len2 - val;
    }
};


// dfs + cache
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> cache(len1+1, vector<int>(len2+1));
        int lcs = dfs(word1, word2, len1, len2, cache);
        return len1 - lcs + len2 - lcs;
    }

private:
    int dfs(string word1, string word2, int m, int n, vector<vector<int>>& cache) {
        if (m == 0 || n == 0) return 0;
        
        if (cache[m][n] > 0) return cache[m][n];
        
        if (word1[m-1] == word2[n-1]) cache[m][n] = 1 + dfs(word1, word2, m-1, n-1, cache);
        else cache[m][n] = max(dfs(word1, word2, m-1, n, cache), dfs(word1, word2, m, n-1, cache));
        return cache[m][n];
    }
};
