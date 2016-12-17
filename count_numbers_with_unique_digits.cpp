class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int sum = 0;
        for (int i = 0; i <= n; ++i) {
            sum += computeNumbersWithNUniqueDigits(i);
        }
        return sum;
    }
    
private:
    int computeNumbersWithNUniqueDigits(int n) {
        if (n < 0 || n > 10) return 0;
        if (n == 0) return 1;
        if (n == 1) return 9;
        int result = 9;
        for (int i = 2; i <= n; ++i) {
            result *= (9-i+2);
        }
        return result;
    }
};
