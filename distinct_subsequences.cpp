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
