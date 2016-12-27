class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string solution;
        dfs(n, 0, 0, solution, result);
        return result;
    }

private:
    void dfs(int n, int lefts, int rights, string solution, vector<string>& result) {
        if ((n == lefts) && (n == rights)) {
            result.emplace_back(solution);
            return ;
        }
    
        if (lefts < n) {
            solution.push_back('(');
            dfs(n, lefts+1, rights, solution, result);
            solution.pop_back();
        }
    
        if (rights < lefts) {
            solution.push_back(')');
            dfs(n, lefts, rights+1, solution, result);
            solution.pop_back();
        }
    }
};
