class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        
        int max_num = pow(10, n)-1;
        for (int i = max_num-1; i > max_num /10; --i) {
            string s = to_string(i), rev = s;
            reverse(rev.begin(), rev.end());
            long product = stol(s+rev);
            for (long x = max_num; x*x >= product; --x) {
                if (product %x == 0) return (int)(product%1337);
            }
        }
        return 0;
    }
};
