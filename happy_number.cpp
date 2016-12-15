class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = sumDigits(slow);
            fast = sumDigits(fast);
            fast = sumDigits(fast);
        } while(slow != fast);
        return slow == 1;
    }

private:
    int sumDigits(int n) {
        int sum = 0;
        while (n) {
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }
};
