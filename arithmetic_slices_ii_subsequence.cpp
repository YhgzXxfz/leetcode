class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.empty()) return 0;
        
        int len = A.size();
        vector<unordered_map<long long, int>> dp(len);
        unordered_set<int> st(A.begin(), A.end());
        int result = 0;
        for (int i = 1; i < len; ++i) {
            for (int j = i-1; j >= 0; --j) {
                long long d = (long long)A[i] - (long long)A[j];
                int tmp = dp[j].count(d) ? dp[j][d] : 0;
                if (tmp) result += tmp;
                if (st.count(A[i]+d)) dp[i][d] += 1 + tmp;
            }
        }
        return result;
    }
};
