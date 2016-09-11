class Solution {
public:
    int integerReplacement(int n) {
        long long num = (long long) n;
        return integerReplacement(num);
    }

private:
    int integerReplacement(long long num) {
        if (num <= 1) return 0;
        
        if (num % 2 == 1) return 1 + min(integerReplacement(num+1), integerReplacement(num-1));
        else return 1 + integerReplacement(num/2);
    }
};
