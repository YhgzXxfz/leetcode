class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        
        int sign = n < 0 ? -1 : 1;
        n = abs(n);
       
        double result = pow(myPow(x, n/2), 2);
        if (n&1) result *= x;
        if (result > INT_MAX || result < INT_MIN) return 0;
        
        return sign == 1 ? result : 1/result;
    }
};
