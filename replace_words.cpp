class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        if (sentence.empty()) return sentence;
        
        auto vec = stringToVector(sentence);
        replaceByRoot(vec, dict);
        return vectorToString(vec);
    }

private:
    vector<string> stringToVector(string s) {
        vector<string> vec;
        int i = 0, len = s.size(), begin = 0;
        while (i < len) {
            while (i < len && s[i] == ' ') i++;
            begin = i;
            while (i < len && s[i] != ' ') i++;
            vec.push_back(s.substr(begin, i-begin));
        }
        return vec;
    }
    
    string vectorToString(vector<string>& vec) {
        string result = vec[0];
        for (int i = 1; i < vec.size(); ++i) result += " "+vec[i];
        return result;
    }
    
    void replaceByRoot(vector<string>& vec, vector<string>& dict) {
        for (auto& word : vec) {
            int root_len = INT_MAX;
            string root = word;
            for (const auto& s : dict) {
                int len = s.size();
                if (len > word.size()) continue;
                
                if (word.substr(0, len) == s) {
                    if (len < root_len) {
                        root_len = len;
                        root = s;
                    }
                }
            }
            word = root;
        }
    }
};
