class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string s1, string s2) { return s1.size() < s2.size(); });
        
        vector<string> result;
        unordered_set<string> st;
        for (auto& word : words) {
            if (canForm(word, st)) result.emplace_back(word);
            st.insert(word);
        }
        return result;
    }

private:
    bool canForm(string word, unordered_set<string>& dict) {
        if (dict.empty()) return false;
        
        int len = word.size();
        int dp[len+1] = {};
        dp[0] = 1;
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(word.substr(j, i-j))) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[len];
    }
};
