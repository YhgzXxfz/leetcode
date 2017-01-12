class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0, z = x^y;
        while (z) {
            count += z&1;
            z >>= 1;
        }
        return count;
    }
};
