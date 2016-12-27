class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord == endWord) return 1;
        
        unordered_set<string> words1, words2;
        words1.insert(beginWord);
        words2.insert(endWord);
        wordList.erase(beginWord);
        wordList.erase(endWord);
        return dfs(words1, words2, wordList, 1);
    }
    
    int dfs(unordered_set<string>& words1, unordered_set<string>& words2, 
        unordered_set<string>& dict, int level) {
        if (words1.empty()) return 0;
        if (words1.size() > words2.size()) return dfs(words2, words1, dict, level);
        unordered_set<string> words3;
        for (auto it = words1.begin(); it != words1.end(); ++it) {
            string word = *it;
            for (auto ch = word.begin(); ch != word.end(); ++ch) {
                char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch)) {
                    if (*ch != tmp) {
                        if (words2.find(word) != words2.end()) return level+1;
                        else if (dict.find(word) != dict.end()) {
                            dict.erase(word);
                            words3.insert(word);
                        }
                    }
                }
                *ch = tmp;
            }
        }
        return dfs(words2, words3, dict, level+1);
    }
};
