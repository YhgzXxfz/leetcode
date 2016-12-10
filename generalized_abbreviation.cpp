class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        int len = word.size();
        for (int i = 0; i < (1<<len); ++i) {
            int count = 0;
            string curr = "";
            for (int j = 0; j < len; ++j) {
                if (i & (1<<j)) count++;
                else {
                    if (count) {
                        curr += to_string(count);
                        count = 0;
                    }
                    curr += word[j];
                }
            }
            if (count) curr += to_string(count);
            result.emplace_back(curr);
        }
        return result;
    }
};
