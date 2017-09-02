class Solution {
public:
    int numDecodings(string s) {
        int len = s.size(), M = 1e9+7;
        long dp[len+1] = {};
        dp[0] = 1;
        dp[1] = helper(s.substr(0,1));
        for (int i = 2; i <= len; ++i) {
            dp[i] = (dp[i-2]*helper(s.substr(i-2,2)) + dp[i-1]*helper(s.substr(i-1,1))) %M;
        }
        return dp[len];
    }
    
private:
    int helper(string s) {
        if (s.size() == 1) {
            if (s[0] == '*') return 9;
            return s[0] == '0' ? 0 : 1;
        }
        
        if (s == "**") return 15;
        else if (s[1] == '*') {
            if (s[0] == '1') return 9;
            return s[0] == '2' ? 6 : 0;
        } else if (s[0] == '*') {
            return s[1] <= '6' ? 2 : 1; 
        } else {
            return stoi(s) >= 10 && stoi(s) <= 26 ? 1 : 0;
        }
    }
};
