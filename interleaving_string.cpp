class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        
        int len1 = s1.size(), len2 = s2.size();
        int dp[len1+1][len2+1] = {};
        for (int i = 0; i <= len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                if (i == 0 && j == 0) dp[i][j] = 1;
                else if (i == 0) dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
                else if (j == 0) dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
                else dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1] || dp[i][j-1] && s2[j-1] == s3[i+j-1];
            }
        }
        return dp[len1][len2];
    }
};
