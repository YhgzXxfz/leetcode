class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        
        int len = s.size();
        int dp[len] = {};
        vector<vector<int>> is_palindrome(len, vector<int>(len,0));
        
        for (int i = len-1; i >= 0; --i) {
            dp[i] = len-1-i;
            for (int j = i; j < len; ++j) {
                if (s[i] == s[j] && (j-i < 2 || is_palindrome[i+1][j-1])) {
                    is_palindrome[i][j] = 1;
                    if (j == len-1) dp[i] = 0;
                    else dp[i] = min(dp[i], dp[j+1]+1);
                }
            }
        }
        return dp[0];
    }
};
