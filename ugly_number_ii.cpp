class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5) return n;
        
        vector<int> result(n, 0);
        result[0] = 1;
        
        int last2 = 0, last3 = 0, last5 = 0;
        for (int i = 1; i < n; ++i) {
            while (result[last2] * 2 <= result[i-1]) ++last2;
            while (result[last3] * 3 <= result[i-1]) ++last3;
            while (result[last5] * 5 <= result[i-1]) ++last5;
            
            result[i] = min(result[last2]*2, min(result[last3]*3, result[last5]*5));
        }
        return result[n-1];
    }
};
