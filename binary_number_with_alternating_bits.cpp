class Solution {
public:
    bool hasAlternatingBits(int n) {
        if (n == 1 || n == 0) return true;
        
        int last = n&1;
        n >>= 1;
        while (n) {
            int curr = n&1;
            n >>= 1;
            if ((last^curr) == 0) return false;
            last = curr;
        }
        return true;
    }
};
