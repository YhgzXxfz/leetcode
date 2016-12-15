class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1 iterative
        while (n > 1 && n%3 == 0) {
            n /= 3;
        }
        return n == 1;
        
        // 2 recursive
        //return (n == 1 || n > 0 && n%3 == 0 && isPowerOfThree(n/3));
        
        
        // 3 math
        //return n > 0 && n == pow(3, round(log(n)/log(3)));
    }
};
