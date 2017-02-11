class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (auto word : dictionary) {
            string abbrev = generateAbbreviation(word);
            mp[abbrev].insert(word);
        }
    }
    
    bool isUnique(string word) {
        string abbrev = generateAbbreviation(word);
        if (mp.find(abbrev) == mp.end()) return true;
        return mp[abbrev].count(word) == mp[abbrev].size();
    }

private:
    string generateAbbreviation(string word) {
        int len = word.size();
        return len <= 2 ? word : word[0]+to_string(len-2)+word[len-1];
    }
    
    unordered_map<string, unordered_set<string>> mp;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
