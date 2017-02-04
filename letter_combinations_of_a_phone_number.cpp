class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if (digits.empty()) return results;
        
        string combination;
        vector<string> tables = vector<string>({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        
        dfs(digits, 0, tables, combination, results);
        return results;
    }

private:    
    void dfs(string digits, int start, vector<string>& tables, string combination,vector<string>& results) {
        if (start == digits.size()) {
            results.emplace_back(combination);
            return;
        }
        
        int curr = digits[start]-'0';
        for (int i = 0; i < tables[curr].size(); ++i) {
            combination.push_back(tables[curr][i]);
            dfs(digits, start+1, tables, combination, results);
            combination.pop_back();
        }
    }
};
