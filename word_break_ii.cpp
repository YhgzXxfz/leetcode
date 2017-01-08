class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (mp.find(s) != mp.end()) return mp[s];

	unordered_set<string> st(wordDict.begin(), wordDict.end());
        // check if need to go further
        vector<string> result; 
        bool found = false;
        for (int i = s.size()-1; i >= 0; --i) {
            if (st.count(s.substr(i))) {
                found = true;
                break;
            }
        }
        if (!found) return result;

        // go further 
        if (st.count(s)) result.emplace_back(s);
        for (int i = s.size()-2; i >= 0; --i) {
            if (st.count(s.substr(0, i+1))) {
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
