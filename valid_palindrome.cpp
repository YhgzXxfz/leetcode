class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if (len <= 1) return true;

        int left = 0, right = len -1;
        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            if (!isalnum(s[right])) {
                right--;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right])) return false;
            
            left++; right--;
        }
        return true;
    }
};
