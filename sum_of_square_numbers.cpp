class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c < 0) return false;
        
        for (int i = 0; i <= sqrt(c); ++i) {
            int b = c - i*i, root = sqrt(b);
            if (root*root == b) return true;
        }
        return false;
    }
};
