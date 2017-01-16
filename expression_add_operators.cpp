class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        
        dfs(num, target, "", result, 0, 0, 0);
        return result;
    }

private:
    void dfs(string num, int target, string solution, vector<string>& result, int start, long eval, long multed) {
        if (start == num.size()) {
            if (target == eval) result.emplace_back(solution);
            return;
        }
        
        for (int i = start; i < num.size(); ++i) {
            if (i != start && num[start] == '0') break;
            
            string curr_str = num.substr(start, i+1-start);
            long curr = stol(curr_str);
            if (start == 0) dfs(num, target, solution+curr_str, result, i+1, curr, curr);
            else {
                dfs(num, target, solution+"+"+curr_str, result, i+1, eval+curr, curr);
                dfs(num, target, solution+"-"+curr_str, result, i+1, eval-curr, -curr);
                dfs(num, target, solution+"*"+curr_str, result, i+1, eval-multed+multed*curr, multed*curr);
            }
        }
    }
};
