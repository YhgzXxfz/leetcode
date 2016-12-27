class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if (digits.empty()) return results;
        
        string combination;
        string tables[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        dfs(digits, 0, tables, combination, results);
        return results;
    }
    
    void dfs(string digits, int levels, string tables[], string combination,vector<string>& results) {
        if (levels == digits.size()) {
            results.emplace_back(combination);
            return;
        }
        
        int curr = digits[levels] - '0';
        for (int i = 0; i < tables[curr].size(); ++i) {
            combination.push_back(tables[curr][i]);
            dfs(digits, levels+1, tables, combination, results);
            combination.pop_back();
        }
    }
};
