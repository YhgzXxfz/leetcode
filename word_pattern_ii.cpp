class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_set<string> st;
        unordered_map<char, string> mp;
        return match(str, 0, pattern, 0, mp, st);
    }

private:
    bool match(string str, int i, string pattern, int j, unordered_map<char, string>& mp, unordered_set<string>& st) {
        int m = str.size(), n = pattern.size();
        if (i == m && j == n) return true;
        if (i == m || j == n) return false;
        
        char c = pattern[j];
        if (mp.find(c) != mp.end()) {
            string s = mp[c];
            int len = s.size();
            if (s != str.substr(i, len)) return false;
            return match(str, i+len, pattern, j+1, mp, st);
        }
        
        for (int k = i; k < m; ++k) {
            string candidate = str.substr(i, k-i+1);
            if (st.count(candidate)) continue;
            
            st.insert(candidate);
            mp[c] = candidate;
            if (match(str, k+1, pattern, j+1, mp, st)) return true;
            st.erase(candidate);
            mp.erase(c);
        }
        return false;
    }
};
