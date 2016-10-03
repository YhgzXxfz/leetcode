class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.size();
        int letters[52] = {};
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') letters[c-'A']++;
            else letters[26 + c-'a']++;
        }
        
        int sum = 0;
        for (int i : letters) {
            if (i % 2 == 0) sum += i;
            else if (sum % 2 == 0) sum += i;
            else sum += i-1;
        }
        
        return sum;
    }
};
