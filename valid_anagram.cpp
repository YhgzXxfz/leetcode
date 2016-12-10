class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        int alphabet[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            alphabet[s[i]-'a']++;
            alphabet[t[i]-'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (alphabet[i]) return false;
        }
        return true;
    }
};
