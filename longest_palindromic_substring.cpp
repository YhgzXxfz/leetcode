class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len < 2) return s;
        
        int max_left = 0, max_len = 1, left, right;
        for (int i = 0; i < len && len-i > max_len/2;) {
            left = right = i;
            
            while (right < len-1 && s[right+1] == s[right]) ++right;
            
            i = right+1;
            while (right < len-1 && left > 0 && s[right+1] == s[left-1]) {
                left--; right++;
            }
            
            if (max_len < right-left+1) {
                max_left = left;
                max_len = right-left+1;
            }
        }
        return s.substr(max_left, max_len);
    }
};
// 
/*
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len < 2) return s;
        
        int begin = 0, end = 0;
        for (int i = 0; i < s.size()-1; ++i) {
            expandAroundCenter(s, i, i);
            expandAroundCenter(s, i, i + 1);
        }
        return s.substr(low, max_len);
    }
    
private:
    void expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--; right++;
        }
        if (right-left-1 > max_len) {
            low = left+1;
            max_len = right-left-1;
        }
    }
    
    int low = 0, max_len = 0;
};
*/
