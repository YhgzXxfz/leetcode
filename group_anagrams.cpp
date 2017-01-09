class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].emplace_back(s);
        }
        
        vector<vector<string>> result;
        for (auto m : mp) {
            result.emplace_back(m.second);
        }
        return result;
    }
};
