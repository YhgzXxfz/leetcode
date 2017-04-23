class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, long> balances;
        for (const auto& t : transactions) {
            balances[t[0]] -= t[2];
            balances[t[1]] += t[2];
        }
        
        vector<long> debts;
        for (const auto& entry : balances) {
            if (entry.second) debts.push_back(entry.second);
        }
        return dfs(0, 0, debts);
    }

private:
    int dfs(int start, int count, vector<long>& debts) {
        while (start < debts.size() && debts[start] == 0) start++;
        
        int result = INT_MAX;
        for (long i = start+1, prev = 0; i < debts.size(); ++i) {
            if (debts[i] != prev && debts[i]*debts[start] < 0) {
                debts[i] += debts[start];
                result = min(result, dfs(start+1, count+1, debts));
                debts[i] -= debts[start];
                prev = debts[i];
            }
        }
        return result == INT_MAX ? count : result;
    }
};
