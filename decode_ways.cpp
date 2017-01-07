class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if (len == 0 || s[0] == '0') return 0;
        if (len == 1) return 1;
        
        int dp[len+1] = {};
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= len; ++i) {
            if (isOneDigit(s[i-1])) dp[i] += dp[i-1];
            if (isTwoDigits(s[i-2], s[i-1])) dp[i] += dp[i-2];
        }
        return dp[len];
    }
    
private:
    bool isOneDigit (char c) {
        return c != '0';
    }
    
    bool isTwoDigits (char c1, char c2) {
        return c1 == '1' || (c1 == '2' && c2 <= '6');
    }
};
