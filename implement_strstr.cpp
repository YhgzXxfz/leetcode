class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        
        int len_h = haystack.size(), len_n = needle.size();
        if (len_h < len_n) return -1;
        
        for (int i = 0; i <= len_h-len_n; ++i) {
            if (haystack.substr(i, len_n) == needle) return i;
        }
        return -1;
    }
};
