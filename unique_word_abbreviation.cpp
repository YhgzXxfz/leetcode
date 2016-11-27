class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string word : dictionary) {
            int len = word.size();
            string abbrev = len <= 2 ? word : word[0]+to_string(len-2)+word[len-1];
            mp[abbrev].insert(word);
        }
    }

    bool isUnique(string word) {
        int len = word.size();
        string abbrev = len <= 2 ? word : word[0]+to_string(len-2)+word[len-1];
        if (mp.find(abbrev) == mp.end()) return true;
        return mp[abbrev].count(word) == mp[abbrev].size();
    }

private:
    unordered_map<string, unordered_set<string>> mp;
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
