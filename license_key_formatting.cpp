class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result;
        for (auto i = S.rbegin(); i < S.rend(); ++i) {
            if (*i != '-') {
                result += (result.size()%(K+1) - K == 0) ? "-" : "";
                result += toupper(*i);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
