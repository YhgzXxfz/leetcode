class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int count[256] = {0}; // initialization is necessary for counting distinct numbers
        int begin = 0, distinct = 0, max_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (count[s[i]] == 0) distinct++;
            count[s[i]]++;
            
            while (distinct > 2) {
                count[s[begin]]--;
                if (count[s[begin]] == 0) distinct--;
                begin++;
            }
            
            max_len = max(max_len, i-begin+1);
        }
        return max_len;
    }
};
