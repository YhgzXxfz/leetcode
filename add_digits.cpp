class Solution {
public:
    int addDigits(int num) {
        // iteration
        /*
        if (num <= 0) return 0;
        int last = 0;
        while (last != num) {
            last = num;
            int sum = 0;
            while (num) {
                sum += num%10;
                num /= 10;
            }
            num = sum;
        }
        return num;
        */
        
        // math
        if (num <= 0) return 0;
        return (num%9 == 0) ? 9 : num%9;
    }
};
