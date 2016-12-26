class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
            if (mp.find(s) != mp.end()) return mp[s];

            // check if need to go further
            vector<string> result; 
            bool found = false;
            for (int i = s.size()-1; i >= 0; --i) {
                if (wordDict.find(s.substr(i)) != wordDict.end()) {
                    found = true;
                    break;
                } 
            }
            if (!found) return result;

            // go further 
            if (wordDict.find(s) != wordDict.end()) result.emplace_back(s);
            for (int i = s.size()-2; i >= 0; --i) {
                if (wordDict.find(s.substr(0, i+1)) != wordDict.end()) {
                    vector<string> rest = wordBreak(s.substr(i+1), wordDict);
                    for (auto temp : rest) {
                        result.emplace_back(s.substr(0, i+1) + " " + temp);
                    }
                } 
            }

            mp[s] = result;
            return result;
    }

private:
    unordered_map<string, vector<string>> mp;
};
