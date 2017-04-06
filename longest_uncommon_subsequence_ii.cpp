class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size(), maxlen = -1;
        for (int i = 0; i < n; i++) {
            bool unique = true;
            for (int j = 0; j < n; j++) {
                if (i != j && isSubsequence(strs[i], strs[j])) {
                    unique = false;
                    break;
                }
            }
            if (unique) maxlen = max(maxlen, (int)strs[i].size());
        }
        return maxlen;
    }
    
private:
    bool isSubsequence(string s1, string s2) {
        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                ++i; ++j;
            } else {
                ++j;
            }
        }
        return s1.size() == i;
    }
};
