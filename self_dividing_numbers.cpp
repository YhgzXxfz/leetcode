class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int x = left; x <= right; ++x) {
            int temp = x;
            bool is_valid = true;
            while (temp) {
                int digit = temp%10;
                temp /= 10;
                if (digit == 0 || x%digit != 0) {
                    is_valid = false;
                    break;
                }
            }
            
            if (is_valid) result.push_back(x);
        }
        return result;
    }
};
