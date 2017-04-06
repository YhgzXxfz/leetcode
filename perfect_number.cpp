class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        
        int sum = 1, root = sqrt(num);
        for (int i = 2; i <= root; ++i) {
            if (num %i == 0) {
                sum += i+num/i;
                if (i == num/i) sum -= i;
            }
        }
        return sum == num;
    }
};
