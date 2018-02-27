class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> mp;
        for (auto c : T) {
            ++mp[c];
        }
        
        string result = "";
        for (auto c : S) {
            if (mp.find(c) != mp.end()) {
                result += string(mp[c], c);
                mp.erase(c);
            }
        }
        for (auto entry : mp) {
            result += string(entry.second, entry.first);
        }
        return result;
    }
};
