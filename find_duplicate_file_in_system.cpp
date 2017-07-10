class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, unordered_set<string>> mp;
        constructMap(paths, mp);
        return fillResult(mp);
    }

private:
    void constructMap(vector<string>& paths, unordered_map<string, unordered_set<string>>& mp) {
        for (const auto& path : paths) {
            parseAndInsert(path, mp);
        }
    }
    
    void parseAndInsert(string path, unordered_map<string, unordered_set<string>>& mp) {
        int blank = path.find_first_of(" ");
        string dir = path.substr(0, blank), filename, content;
        int len = path.size(), filebegin = blank+1, left = 0, right = 0;
        for (int i = blank+1; i < len; ++i) {
            if (path[i] == '(') {
                left = i+1;
                filename = path.substr(filebegin, i-filebegin);
            } else if (path[i] == ')') {
                right = i;
                content = path.substr(left, right-left);
                if (!content.empty()) mp[content].insert(dir+"/"+filename);
            } else if (path[i] == ' ') {
                filebegin = i+1;
            }
        }
    }
    
    vector<vector<string>> fillResult(unordered_map<string, unordered_set<string>>& mp) {
        vector<vector<string>> result;
        for (auto paths : mp) {
            if (paths.second.size() > 1) {
                result.emplace_back(vector<string>());
                for (auto path : paths.second) {
                    result[result.size()-1].push_back(path);
                }
            }
        }
        return result;
    }
};
