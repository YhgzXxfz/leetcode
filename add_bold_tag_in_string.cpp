class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int len = s.size();
        vector<int> is_bold(len, 0);
        int pos = -1;
        for (auto word : dict) {
            do {
                pos = s.find(word, pos+1);
                if (pos != string::npos) {
                    for (int i = pos; i < pos + word.size(); ++i) {
                        is_bold[i] = 1;
                    }
                }
            } while (pos != string::npos);
        }
        
        string result;
        bool b = false;
        for (int i = 0; i < len; ++i) {
            if (!is_bold[i]) {
                if (b) {
                    result += "</b>";
                    b = false;
                }
            } else {
                if (!b) {
                    result += "<b>";
                    b = true;
                }
            }
            result += s[i];
        }
        if (b) result += "</b>";
        return result;
    }
};
