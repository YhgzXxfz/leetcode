class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int i = 1, j = 0, len = str.size();
        int dp[len+1] = {};
        while (i < len) {
            if (str[i] == str[j]) dp[++i] = ++j;
            else if (j == 0) i++;
            else j = dp[j];
        }
        return dp[len] && dp[len] % (len-dp[len]) == 0;
    }
};
