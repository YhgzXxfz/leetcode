class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        if (s.empty() || t.empty()) return result;
        
        unordered_map<char, int> dict, window;
        for (int i = 0; i < t.size(); i++){
            dict[t[i]]++;
        }
        
        int min_len = INT_MAX;
        int count = 0, begin = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (dict.find(c) != dict.end()) {
                window[c]++;
                if(window[c] <= dict[c]) count++;
            }
            if (count >= t.size()) {
                while (dict.find(s[begin]) == dict.end() || window[s[begin]] > dict[s[begin]]){
                    window[s[begin]]--;
                    begin++;
                }
                if (i-begin+1 < min_len){
                    min_len = i-begin+1;
                    result = s.substr(begin, min_len);
                }
            }
        }
        return result;
    }
};
