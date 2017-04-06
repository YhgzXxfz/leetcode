class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len));
        
        for (int i = len-1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < len; ++j) {
                if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1]+2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][len-1];
    }
};




// memory limit exceeded
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int>> cache(len, vector<int>(len));
        return dfs(s, 0, len-1, cache);
    }
    
private:
    int dfs(string s, int left, int right, vector<vector<int>>& cache) {
        if (cache[left][right]) return cache[left][right];
        
        if (left > right) return 0;
        if (left == right) return 1;
        
        if (s[left] == s[right]) cache[left][right] = dfs(s, left+1, right-1, cache) +2;
        else cache[left][right] = max(dfs(s, left+1, right, cache), dfs(s, left, right-1, cache));
        
        return cache[left][right];
    }
};
