class Solution {
public:
    int findNthDigit(int n) {
        long count = 9;
        int len = 1, start_number = 1;
        
        while (n > len*count) {
            n -= len*count;
            len++;
            count *= 10;
            start_number *= 10;
        }
        
        start_number += (n-1)/len;
        string s = to_string(start_number);
        return s[(n-1)%len]-'0';
    }
};
