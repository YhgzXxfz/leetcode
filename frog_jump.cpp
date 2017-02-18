
// dfs + cache
/*
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        vector<vector<int>> cache(len, vector<int>(len, 0));
        return dfs(stones, 0, 0, cache) == 1;
    }

private:
    bool dfs(vector<int>& stones, int start, int jump, vector<vector<int>>& cache) {
        if (cache[start][jump]) return cache[start][jump];
        
        for (int i = start+1; i < stones.size(); ++i) {
            int gap = stones[i]-stones[start];
            if (gap >= jump-1 && gap <= jump+1) {
                if (dfs(stones, i, gap, cache) == 1) {
                    cache[i][gap] = 1;
                    return cache[i][gap];
                }
            }
        }
        cache[start][jump] = start == stones.size()-1 ? 1 : 0;
        return cache[start][jump];
    }
};
*/


// dp
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones.empty()) return true;
        
        int len = stones.size();
        
        unordered_map<int, unordered_set<int>> dp;
        dp[0].insert(1);
        unordered_set<int> st(stones.begin(), stones.end());
        int curr = 0, next = 0;
        
        for (int i = 0; i < len; ++i) {
            curr = stones[i];
            
            if (curr == stones[len-1]) break;
        
            for (auto jump : dp[curr]) {
                int next = curr+jump;
                if (st.count(next) && next > curr) {
                    dp[next].insert(jump-1);
                    dp[next].insert(jump);
                    dp[next].insert(jump+1);
                }
            }
        }
        return dp.find(curr) != dp.end() && dp[curr].size() > 0;
    }
};
