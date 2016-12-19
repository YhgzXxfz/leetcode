class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        
        string solution;
        for (int i = 1; i <= num.size(); ++i) {
            string s = num.substr(0,i);
            long curr = stol(s);
            if (to_string(curr).size() != s.size()) continue;
            
            dfs(result, s, i, curr, curr, '#', num, target);
        }
        
        return result;
    }
    
    void dfs(vector<string>& result, string solution, int pos, long curr, long prev, 
        char op, const string& num, const int target) {
        if (pos == num.size() && curr == target) {
            result.push_back(solution);
            return;
        }
        
        for (int i = pos+1; i <= num.size(); ++i) {
            string s = num.substr(pos, i-pos);
            long now = stol(s);
            if (to_string(now).size() != s.size()) continue;
            
            dfs(result, solution+'+'+s, i, curr+now, now, '+', num, target);
            dfs(result, solution+'-'+s, i, curr-now, now, '-', num, target);
            dfs(result, solution+'*'+s, i, 
                (op == '-') ? curr+prev-prev*now : ((op == '+') ? curr-prev+prev*now : prev*now), prev*now, op, num, target);
        }
    }
};
