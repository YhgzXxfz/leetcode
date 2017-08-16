class Solution {
public:
    int newInteger(int n) {
        int result = 0, s = 1;
        while (n > 0) {
            result += n%9 * s;
            n /= 9;
            s *= 10;
        }
        return result;
    }
};
