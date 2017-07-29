class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [&](vector<int>& p1, vector<int>& p2) {
            return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] < p2[0];
        });
        
        int len = pairs.size();
        vector<int> dp(len, 1);
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] < pairs[i][0]) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
