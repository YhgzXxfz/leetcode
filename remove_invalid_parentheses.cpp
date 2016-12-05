class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return {""};
        
        queue<string> q;
        unordered_set<string> visited;
        
        q.push(s); visited.insert(s);
        bool found = false;
        while (!q.empty()) {
            string str = q.front();
            q.pop();
            if (isValid(str)) {
                result.push_back(str);
                found = true;
            }
            
            if (found) continue;
            
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] != '(' && str[i] != ')') continue;
                
                string t = str.substr(0, i) + str.substr(i+1);
                if (!visited.count(t)) {
                    q.push(t);
                    visited.insert(t);
                }
            }
        }
        return result;
    }
    
    bool isValid(string s) {
        int count = 0;
        for (auto c : s) {
            if (c == '(') ++count;
            if (c == ')') {
                if (count == 0) return false;
                else --count;
            }
        }
        return count == 0;
    }
};
