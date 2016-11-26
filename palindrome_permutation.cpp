class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> count(256, 0);
        for (auto c : s) {
            count[c]++;
        }
        int odd_occurance = 0;
        for (int i = 0; i < 256; i++) {
            if (count[i] % 2 != 0) odd_occurance++;
            if (odd_occurance > 1) return false;
        }
        return true;
    }
};
