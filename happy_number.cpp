class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
        while (true) {
            n = sumDigit(n);
            if (n == 1) return true;
            if (find(non_happy_numbers.begin(), non_happy_numbers.end(), n) != non_happy_numbers.end()) return false;
        }
    }

private:
    int sumDigit(int n) {
        int sum = 0;
        while (n) {
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }
    vector<int> non_happy_numbers = {4, 16, 20, 37, 42, 58, 89, 145};
};
