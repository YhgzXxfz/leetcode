class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        
        vector<int> dp(len+1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDict.count(s.substr(j,i-j))) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[len];
    }
};
