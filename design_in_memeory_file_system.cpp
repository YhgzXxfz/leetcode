class TrieNode {
public:
    string content;
    bool is_file;
    unordered_map<string, TrieNode*> children;
    
    TrieNode() : is_file(false) {}
};

class FileSystem {
public:
    FileSystem() {
        root = new TrieNode();
    }
    
    vector<string> ls(string path) {
        auto strs = getStr(path);
        auto curr = root;
        for (auto str : strs) {
            curr = curr->children[str];
        }
        
        if (curr->is_file) return { strs.back() };
        
        vector<string> result;
        for (auto child : curr->children) result.push_back(child.first);
        sort(result.begin(), result.end());
        return result;
    }
    
    void mkdir(string path) {
        auto strs = getStr(path);
        auto curr = root;
        for (auto str : strs) {
            if (!curr->children.count(str)) curr->children[str] = new TrieNode();
            curr = curr->children[str];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        auto strs = getStr(filePath);
        auto curr = root;
        for (auto str : strs) {
            if (!curr->children.count(str)) curr->children[str] = new TrieNode();
            curr = curr->children[str];
        }
        curr->is_file = true;
        curr->content += content;
    }
    
    string readContentFromFile(string filePath) {
        auto strs = getStr(filePath);
        auto curr = root;
        for (auto str : strs) {
            curr = curr->children[str];
        }
        return curr->content;
    }

private:
    vector<string> getStr(string path) {
        vector<string> vec;
        int begin = 1, i = 1;
        while (i <= path.size()) {
            if (begin != i && (i == path.size() || path[i] == '/')) {
                vec.push_back(path.substr(begin, i-begin));
                begin = i+1;
            }
            ++i;
        }
        return vec;
    }
    
    TrieNode* root;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
