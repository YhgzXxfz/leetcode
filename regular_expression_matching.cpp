// dp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        dp[0][0] = 1;
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j > 1 && '*' == p[j-1] && dp[0][j-2];
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] != '*') dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                else dp[i][j] = dp[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};

// dfs
/*
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p[1] == '*') return isMatch(s, p.substr(2)) || (p[0] == '.' && s[0] || s[0] == p[0]) && isMatch(s.substr(1), p);
        if (p[0] == '.') return s[0] && isMatch(s.substr(1), p.substr(1));
        return s[0] == p[0] && isMatch(s.substr(1), p.substr(1));
    }
};
*/
