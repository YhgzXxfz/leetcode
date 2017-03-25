class Solution {
public:
    	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        	if (beginWord == endWord) return 1;
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        
		unordered_set<string> words1, words2, dict(wordList.begin(), wordList.end());
        	words1.insert(beginWord);
        	words2.insert(endWord);
        	dict.erase(beginWord);
        	dict.erase(endWord);
        	return dfs(words1, words2, dict, 1);
    	}
    
private:
    	int dfs(unordered_set<string>& words1, 
		unordered_set<string>& words2, 
        	unordered_set<string>& dict, 
		int level) {
        
		if (words1.empty()) return 0;
        	if (words1.size() > words2.size()) return dfs(words2, words1, dict, level);
       
		for (auto word : words1) dict.erase(word);
		for (auto word : words2) dict.erase(word);
 
		unordered_set<string> intermediate;
		int has_shortcut = constructIntermediate(intermediate, words1, words2, dict);
		if (has_shortcut) return level+1;
		return dfs(words2, words3, dict, level+1);
    	}

	int constructIntermediate(unordered_set<string>& intermediate,
				unordered_set<string>& words1,
				unordered_set<string>& words2,
				unordered_set<string>& dict) {
		for (auto it = words1.begin(); it != words1.end(); ++it) {
			string word = *it;
			for (auto ch = word.begin(); ch != word.end(); ++ch) {
				char tmp = *ch;
				for (*ch = 'a'; *ch <= 'z'; ++(*ch)) {
					if (words2.count(word)) return 1;
					else if (dict.count(word)) {
						intermediate.insert(word);
					}
				}
				*ch = tmp;
			}
		}
		return 0;
	}
};
