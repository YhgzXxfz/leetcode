class Solution {
public:
    bool checkRecord(string s) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;
        if (mp['A'] > 1) return false;
        
        for (int i = 2; i < s.size(); ++i) {
            if (s[i-2] == 'L' && s[i-1] == 'L' && s[i] == 'L') return false;
        }
        return true;
    }
};
