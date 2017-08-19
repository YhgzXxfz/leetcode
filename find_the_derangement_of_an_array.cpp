class Solution {
public:
    int findDerangement(int n) {
        int M = 1e9+7;
        long result = 1;
        for (int i = 1; i <= n; ++i) {
            result = (i*result %M + (i &1 ? -1 : 1)) %M;
        }
        return result;
    }
};
