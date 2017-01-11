class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() > t.size()) return isOneEditDistance(t,s);
        const int len_s = s.size(), len_t = t.size(), diff = len_t-len_s;
        if (diff > 1) return false;
        
        int i = 0, j = 0;
        while (i < len_s && j < len_t && s[i] == t[j]) {
            i++; j++;
        }
        if (i == len_s) return j+1 == len_t;
        
        j++;
        if (diff == 0) i++;
        while (i < len_s && j < len_t && s[i] == t[j]) {
            i++; j++;
        }
        return i == len_s && j == len_t;
    }
};
