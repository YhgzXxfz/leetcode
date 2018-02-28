class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        queue<string> q;
        q.push(S);
        for (int i = 0; i < S.size(); ++i) {
            if (isdigit(S[i])) continue;
            
            int len = q.size();
            for (int j = 0; j < len; ++j) {
                string curr = q.front();
                q.pop();
                curr[i] ^= (1 << 5);
                q.push(curr);
                curr[i] ^= (1 << 5);
                q.push(curr);
            }
        }
        vector<string> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};


/*
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        dfs(S, result, 0);
        return result;
    }
    
private:
    void dfs(string& S, vector<string>& result, int index) {
        if (index == S.size()) {
            result.push_back(S);
            return ;
        }
        
        dfs(S, result, index+1);
        if (isalpha(S[index])) {
            S[index] ^= (1 << 5);
            dfs(S, result, index+1);
            S[index] ^= (1 << 5);
        }
    }
};
*/
