class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int dict[256] = {0}, begin = 0, max_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (dict[s[i]]) {
                dict[s[begin]]--;
                begin++;
            }
            dict[s[i]]++;
            max_len = max(max_len, i-begin+1);
        }
        return max_len;
    }
};
