class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size(), count = 0;
        for (int size = 1; size <= len; ++size) {
            for (int i = 0; i+size-1 < len; ++i) {
                string candidate = s.substr(i,size);
                if (isPalindrome(candidate)) count++;
            }
        }
        return count;
    }

private:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }
};
