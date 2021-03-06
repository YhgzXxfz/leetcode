class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return PowMod(superPow(a, b), 10) * PowMod(a, last_digit) % base;
    }
    
private:
    int PowMod(int a, int k) {
        a %= base;
        int result = 1;
        for (int i = 0; i < k; ++i) {
            result = (result * a) % base;
        }
        return result;
    }
    
    const int base = 1337;
};
