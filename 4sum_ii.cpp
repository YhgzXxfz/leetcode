class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int result = 0, len = A.size();
        unordered_map<int,int> ab, cd;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                ab[A[i]+B[j]]++;
                cd[C[i]+D[j]]++;
            }
        }
        for (auto x : ab) result += x.second * cd[-x.first];
        return result;
    }
};
