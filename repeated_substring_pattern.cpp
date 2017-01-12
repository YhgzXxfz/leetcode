class Solution {
public:
    // substring 
    bool repeatedSubstringPattern(string str) {
        int len = str.size();
        bool flag;
        for (int i = len/2; i >= 1; --i) {
            if (len%i) continue;
            
            flag = true;
            string sample = str.substr(0,i);
            for (int j = i; j < len; j += i) {
                if (str.substr(j,i) != sample) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }

    // dp
    /*
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
    */
};
