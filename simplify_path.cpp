class Solution {
public:
    string simplifyPath(string path) {
        string result = "", temp;
        vector<string> stack;
        stringstream ss(path);
        
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".") continue;
            else if (temp == ".." && !stack.empty()) stack.pop_back();
            else if (temp != "..") stack.push_back(temp);
        }
        
        for (auto str : stack) {
            result += "/" + str;
        }
        return result.empty() ? "/" : result;
    }
};
