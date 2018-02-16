class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> dict(26, 0);
        for (auto c : licensePlate) {
            if (c >= 'A' && c <= 'Z') dict[c-'A']++;
            else if (c >= 'a' && c <= 'z') dict[c-'a']++;
        }
        
        vector<int> temp = dict;
        string result = "";
        for (auto word : words) {
            temp = dict;
            for (auto c : word) {
                if (temp[c-'a'] == 0) continue;
                
                temp[c-'a']--;
                if (accumulate(temp.begin(), temp.end(), 0) == 0) {
                    if (result.empty() || word.size() < result.size()) result = word;
                }
            }
        }
        return result;
    }
};
