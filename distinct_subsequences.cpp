class Solution {
public:
    int numDistinct(string s, string t) {
        int lenS = s.size(), lenT = t.size();
        
        vector<int> dp(lenT+1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < lenS; ++i) {
            for (int j = lenT-1; j >= 0; --j) {
                dp[j+1] += s[i] == t[j] ? dp[j] : 0;
            }
        }
        return dp[lenT];
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int lenS = s.size(), lenT = t.size();
        
        vector<vector<int>> dp(lenS+1, vector<int>(lenT+1,0));
        for (int i = 0; i <= lenS; ++i) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= lenS; ++i) {
            for (int j = 1; j <= lenT; ++j) {
                if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[lenS][lenT];
    }
};
