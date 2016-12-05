class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string> > paths;
        vector<string> path(1, beginWord);
        if (beginWord == endWord) {
            paths.push_back(path);
            return paths;
        }
        
        unordered_set<string> words1, words2;
        words1.insert(beginWord);
        words2.insert(endWord);
        
        unordered_map<string, vector<string> > nexts;
        bool words1_is_begin = false;
        
        if (findLaddersHelper(words1, words2, wordList, nexts, words1_is_begin)) 
            getPath(beginWord, endWord, nexts, path, paths);
        return paths;
    }
    
private:
    bool findLaddersHelper(
        unordered_set<string>& words1,
        unordered_set<string>& words2,
        unordered_set<string>& dict,
        unordered_map<string, vector<string> >& nexts,
        bool& words1_is_begin) {
        words1_is_begin = !words1_is_begin;
        if (words1.empty()) return false;
        if (words1.size() > words2.size()) return findLaddersHelper(words2, words1, dict, nexts, words1_is_begin);
        for (auto word : words1)
            dict.erase(word);
        for (auto word : words2)
            dict.erase(word);
        
        unordered_set<string> words3;
        bool reach = false;
        for (auto it = words1.begin(); it != words1.end(); ++it) {
            string word = *it;
            for (auto ch = word.begin(); ch != word.end(); ++ch) {
                char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch)) {
                    if (*ch != tmp) {
                        if (words2.find(word) != words2.end()) {
                            reach = true;
                            words1_is_begin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                        } else if (!reach && dict.find(word) != dict.end()) {
                            words3.insert(word);
                            words1_is_begin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                        }
                    }
                }
                *ch = tmp;
            }
        }
        return reach || findLaddersHelper(words2, words3, dict, nexts, words1_is_begin);
    }
    
    void getPath(
        string beginWord,
        string &endWord,
        unordered_map<string, vector<string> >& nexts,
        vector<string> &path,
        vector<vector<string> >& paths) {
        if (beginWord == endWord) paths.push_back(path);
        else {
            for (auto next : nexts[beginWord]) {
                path.push_back(next);
                getPath(next, endWord, nexts, path, paths);
                path.pop_back();
            }
        }
    }
};
