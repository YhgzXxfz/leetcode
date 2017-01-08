class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int words = 0, n = sentence.size();
        unordered_map<int ,int> mp;
        for (int i = 0; i < rows; ++i) {
            int start = words % n;
            if (mp.find(start) == mp.end()) {
                int count = 0, len = 0;
                for (int i = start; len < cols; i = (i+1) % n) {
                    if (len + sentence[i].size() > cols) break;
                    len += sentence[i].size() +1;
                    count++;
                }
                words += count;
                mp[start] = count;
            } else {
                words += mp[start];
            }
        }
        return words/n;
    }
};
