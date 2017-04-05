class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string first = "qwertyuiop", second = "asdfghjkl", third = "zxcvbnm";
        bool in_first = false, in_second = false, in_third = false;
        vector<string> result;
        for (auto word : words) {
            in_first = in_second = in_third = false;
            for (char w : word) {
                char c = tolower(w);
                if (first.find(c) != string::npos) in_first = true;
                if (second.find(c) != string::npos) in_second = true;
                if (third.find(c) != string::npos) in_third = true;
            }
            if (in_first && !in_second && !in_third || 
                !in_first && in_second && !in_third || 
                !in_first && !in_second && in_third) 
                result.emplace_back(word);
        }
        return result;
    }
};
