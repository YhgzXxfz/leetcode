class TrieNode {
public:
    // Initialize your data structure here.
    bool is_string;
    unordered_map<char, TrieNode*> leaves; 
    TrieNode() {
        is_string = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* curr = root;
        for (auto c : word) {
            if (!curr->leaves.count(c)) curr->leaves[c] = new TrieNode();
            curr = curr->leaves[c];
        }
        curr->is_string = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = childSearch(word);
        if (node) return node->is_string;
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return childSearch(prefix);
    }
    
    TrieNode* childSearch(string word) {
        TrieNode* curr = root;
        for (auto c : word) {
            if (curr->leaves.count(c)) curr = curr->leaves[c];
            else return nullptr;
        }
        return curr;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
