class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) return 0;
        
        int len = A.size();
        int weighted_sum = 0, non_weighted_sum = 0;
        for (int i = 0; i < len; ++i) {
            weighted_sum += i * A[i];
            non_weighted_sum += A[i];
        }
        
        int max_weighted_sum = weighted_sum, last_weighted_sum = weighted_sum, new_weighted_sum = 0;
        for (int i = 1; i < len; ++i) {
            new_weighted_sum = last_weighted_sum + (non_weighted_sum-A[len-i]) - (len-1)*A[len-i];
            max_weighted_sum = max(max_weighted_sum, new_weighted_sum);
            last_weighted_sum = new_weighted_sum;
        }
        return max_weighted_sum;
    }
};
