class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.size(), count = 0;
        for (auto c : word) {
            if ('Z'-c >= 0) count++;
        }
        return count == 0 || count == len || count == 1 && isupper(word[0]);
    }
};
