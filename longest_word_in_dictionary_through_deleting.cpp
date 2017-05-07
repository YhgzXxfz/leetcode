class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<string> results;
        for (const auto& candidate : d) {
            if (isSubsequence(candidate, s)) results.push_back(candidate);
        }
        auto comp = [&](string a, string b) {
            return a.size() == b.size() ? a < b : a.size() > b.size();
        };
        sort(results.begin(), results.end(), comp);
        return results.empty() ? "" : *results.begin();
    }

private:
    bool isSubsequence(string candidate, string s) {
        int l_c = candidate.size(), l_s = s.size();
        if (l_c > l_s) return false;
        
        int i = 0, j = 0;
        while (i < l_c) {
            if (candidate[i] == s[j]) {
                i++; j++;
            } else {
                if (j < l_s) j++;
                else break;
            }
        }
        return i == l_c;
    }
};
