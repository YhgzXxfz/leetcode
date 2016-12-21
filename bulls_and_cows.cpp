class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.size();
        vector<int> digits_s(10, 0);
        vector<int> digits_g(10, 0);
        
        int bulls = 0, cows = 0;
        for (int i = 0; i < len; ++i) {
            if (secret[i] == guess[i]) ++bulls;
            else {
                digits_s[secret[i]-'0']++;
                digits_g[guess[i]-'0']++;
            }
        }
        
        for (int i = 0; i < 10; ++i) {
            cows += min(digits_s[i], digits_g[i]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
