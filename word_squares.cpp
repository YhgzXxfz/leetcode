class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        unordered_map<string, vector<string>> mp;
        int len = words[0].size();
        for (auto word : words) {
            for (int i = 0; i < len; ++i) {
                mp[word.substr(0, i)].emplace_back(word);
            }
        }
        
        vector<vector<string>> result;
        vector<string> solution(len);
        dfs(result, solution, 0, mp, len);
        return result;
    }

private:
    void dfs(vector<vector<string>>& result, vector<string>& solution, int step, unordered_map<string, vector<string>>& mp, int len) {
        if (step == len) {
            result.emplace_back(solution);
            return;
        }
        
        string prefix;
        for (int i = 0; i < step; ++i) {
            prefix += solution[i][step];
        }
        
        for (auto word : mp[prefix]) {
            solution[step] = word;
            dfs(result, solution, step+1, mp, len);
        }
    }
};
