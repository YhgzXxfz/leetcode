class Solution {
public:
    int titleToNumber(string s) {
        long long result = 0;
        for (auto c : s) {
            result = result*26 + c-'A'+1;
            if (result > INT_MAX) return 0;
        }
        return result;
    }
};
