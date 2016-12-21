class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int result = 0;
        unordered_map<int,int> ab, cd;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                ab[A[i]+B[j]]++;
                cd[C[i]+D[j]]++;
            }
        }
        for (auto x : ab) result += x.second * cd[-x.first];
        return result;
    }
};
