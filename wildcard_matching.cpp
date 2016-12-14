class Solution {
public:
    bool isMatch(string s, string p) {
        int p_star = -1, s_last = 0;
        int i = 0, j = 0;
        
        while (i != s.size()) {
            if (s[i] == p[j] || p[j] == '?') {
                i++; j++; continue;
            }
            if (p[j] == '*') {
                p_star = j; j++;
                s_last = i; continue;
            }
            if (p_star != -1) {
                j = p_star+1;
                i = ++s_last;
                continue;
            }
            return false;
        }
        
        while (j != p.size() && p[j] == '*') j++;
        return j == p.size();
    }
};
