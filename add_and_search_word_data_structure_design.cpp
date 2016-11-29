class TrieNode {
public:
    bool is_string;
    unordered_map<char, TrieNode*> leaves;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
        root->is_string = true;
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        auto p = root;
        for (auto c : word) {
            if (!p->leaves.count(c)) p->leaves[c] = new TrieNode();
            p = p->leaves[c];
        }
        p->is_string = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return SearchWord(word, root, 0);
    }
    
    bool SearchWord(string word, TrieNode* node, int s) {
        if (s == word.size()) return node->is_string;
        
        if (node->leaves.count(word[s])) return SearchWord(word, node->leaves[word[s]], s+1);
        else if (word[s] == '.') {
            for (auto i : node->leaves) {
                if (SearchWord(word, i.second, s+1)) return true;
            }
        }
        return false;
    }
    
private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
