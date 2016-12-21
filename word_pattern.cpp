class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> p_map;
        unordered_map<string, int> s_map;
        istringstream in(str);
        
        int i = 0, len = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == len || p_map[pattern[i]] != s_map[word]) return false;
            
            p_map[pattern[i]] = s_map[word] = i+1;
        }
        return i == len;
    }
};
