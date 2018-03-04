// O(N), O(26*len)
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto word : dict) st.insert(word);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            for (int j = 0; j < 26; ++j) {
                if (c == 'a'+j) continue;
                word[i] = 'a'+j;
                if (st.count(word)) return true;
            }
            word[i] = c;
        }
        return false;
    }
    
private:
    unordered_set<string> st;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */



// O(1), O(26*len*N)
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto word : dict) {
            for (int i = 0; i < word.size(); ++i) {
                char c = word[i];
                for (int j = 0; j < 26; ++j) {
                    if (c == j+'a') continue;
                    word[i] = j+'a';
                    st.insert(word);
                }
                word[i] = c;
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return st.count(word);
    }
    
private:
    unordered_set<string> st;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
