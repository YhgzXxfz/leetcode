class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = s.size();
        if (len < 1) return 0;
        
        unordered_map<char, int> mp;
        int left = 0, right = 0, max_length = 0;
        while (right < len) {
            if (mp.size() <= 2) {
                mp[s[right]] = right;
                right++;
            }
            if (mp.size() > 2) {
                int left_most = len;
                for (auto& entry : mp) {
                    left_most = min(left_most, entry.second);
                }
                mp.erase(s[left_most]);
                left = left_most+1;
            }
            max_length = max(max_length, right-left);
        }
        return max_length;
    }
};
