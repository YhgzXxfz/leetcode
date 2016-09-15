class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len_s = s.size(), len_t = t.size();
        int p_s = 0, p_t = 0;
        while (p_s < len_s) {
            while (p_t < len_t && t[p_t] != s[p_s]) p_t++;
            if (p_t == len_t) return false;
            p_s++;p_t++;
        }
        return true;
    }
};
