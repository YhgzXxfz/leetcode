class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.size();
        
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        int pos;
        for (pos = len ; pos >= 0; --pos) {
            if (rev_s.substr(len-pos) == s.substr(0, pos)) break;
        }
        return rev_s.substr(0, len-pos) +s;
    }
};
