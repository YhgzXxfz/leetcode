class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string>> result;
        vector<string> path(1, beginWord);
        if (beginWord == endWord) {
            result.emplace_back(path);
            return result;
        }
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return result;

        unordered_set<string> words1, words2, dict(wordList.begin(), wordList.end());
        words1.insert(beginWord);
        words2.insert(endWord);
        
        unordered_map<string, vector<string>> mp;
        bool words1_is_begin = false;
        if (dfs(words1, words2, dict, mp, words1_is_begin)) 
            getPath(beginWord, endWord, mp, path, result);
            
        return result;
    }
    
private:
    bool dfs(unordered_set<string>& words1, unordered_set<string>& words2, unordered_set<string>& dict, unordered_map<string, vector<string>>& mp, bool& words1_is_begin) {
        
        words1_is_begin = !words1_is_begin;
        if (words1.empty()) return false;
        if (words1.size() > words2.size()) return dfs(words2, words1, dict, mp, words1_is_begin);
        for (auto word : words1) dict.erase(word);
        for (auto word : words2) dict.erase(word);
        
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
                            words1_is_begin ? mp[*it].push_back(word) : mp[word].push_back(*it);
                        } else if (!reach && dict.find(word) != dict.end()) {
                            words3.insert(word);
                            words1_is_begin ? mp[*it].push_back(word) : mp[word].push_back(*it);
                        }
                    }
                }
                *ch = tmp;
            }
        }
        return reach || dfs(words2, words3, dict, mp, words1_is_begin);
    }
    
    void getPath(string begin, string &end, unordered_map<string, vector<string>>& mp, vector<string> &path, vector<vector<string>>& result) {
        if (begin == end) {
            result.push_back(path);
            return ;
        }
        
        for (auto next : mp[begin]) {
            path.push_back(next);
            getPath(next, end, mp, path, result);
            path.pop_back();
        }
    }
};
