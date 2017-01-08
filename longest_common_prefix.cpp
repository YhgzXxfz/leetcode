class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if (strs.empty()) return prefix;
        
        for (int i = 0; i < strs[0].size(); ++i) {
            int c = strs[0][i];
            for (auto& s : strs) {
                if (s.empty() || s.size() <= i || s[i] != c) return prefix;
            }
            prefix += c;
        }
        return prefix;
    }
};
