class Solution {
public:
    int characterReplacement(string s, int k) {
        int begin = 0, i = 0, cache[91] = {};
        while (i < s.size()) {
            cache[s[i++]]++;
            if (i-begin - *max_element(cache+65, cache+91) > k) cache[s[begin++]]--;
        }
        return i-begin;
    }
};
