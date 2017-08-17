class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int len = dict.size();
        vector<string> result(len);
        vector<int> prefix(len);
        for (int i = 0; i < len; ++i) {
            prefix[i] = 1;
            result[i] = abbreviate(dict[i], 1);
        }
        
        for (int i = 0; i < len; ++i) {
            while (true) {
                unordered_set<int> st;
                for (int j = i+1; j < len; ++j) {
                    if (result[i] == result[j]) st.insert(j);
                }
                if (st.empty()) break;
                
                st.insert(i);
                
                for (auto k : st) {
                    result[k] = abbreviate(dict[k], ++prefix[k]);
                }
            }
        }
        return result;
    }

private:
    string abbreviate(string s, int k) {
        int len = s.size();
        if (len-2 <= k) return s;
        
        return s.substr(0, k) + to_string(len-1-k) + s.substr(len-1);
    }
};
