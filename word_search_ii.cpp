class TrieNode {
public:
    bool is_string;
    TrieNode* next[26];
    TrieNode(bool temp=false){
        is_string = temp;
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    Trie() {
        root=new TrieNode();
    }
    
    ~Trie() { delete root; }
  
    void insert(string word){
        TrieNode* curr = root;
        for(auto c : word){
            if (!curr->next[c-'a']) curr->next[c-'a'] = new TrieNode();
            curr = curr->next[c-'a'];
        }
        curr->is_string = true;
    }
    
    bool startWith(string prefix){
        return search(prefix);
    }
    
    bool find(string word){
        auto node = search(word);
        if (!node) return false;
        return node->is_string;
    }

private:
    TrieNode* search(string word) {
        auto curr = root;
        for (auto c : word) {
            if (!curr->next[c-'a']) return nullptr;
            curr = curr->next[c-'a'];
        }
        return curr;
    }
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        string word;
        unordered_set<string> st;
        int m = board.size(), n = board[0].size();
        Trie* trie = new Trie();
        
        for (auto word : words) {
            trie->insert(word);
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, trie, i, j, st, word);
            }
        }
        
        for (auto word : st) result.emplace_back(word);
        return result;
    }
    
    void dfs(vector<vector<char>>& board, Trie* trie, int x, int y, unordered_set<string>& st, string word) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == '\0') return ;
        
        word += board[x][y];
        if (!trie->startWith(word)) return;
        if (trie->find(word)) st.insert(word);
        
        char t = board[x][y];
        board[x][y] = '\0';
        dfs(board, trie, x+1, y, st, word);
        dfs(board, trie, x, y+1, st, word);
        dfs(board, trie, x-1, y, st, word);
        dfs(board, trie, x, y-1, st, word);
        board[x][y] = t;
    }
};
