class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        for (int i = 1; i <= len/2; ++i) {
            for (int j = 1; max(j, i) <= len-i-j; ++j) {
                if (isValid(i, j, num)) return true;
            }
        }
        return false;
    }

private:
    bool isValid(int i, int j, string num) {
        if (num[0] == '0' && i > 1) return false;
        if (num[i] == '0' && j > 1) return false;
        
        string sum;
        long x1 = stol(num.substr(0, i)), x2 = stol(num.substr(i, j));
        for (int start = i+j; start != num.size(); start += sum.size()) {
            x2 = x2+x1;
            x1 = x2-x1;
            sum = to_string(x2);
            if (num.substr(start).find(sum) != 0) return false;
        }
        return true;
    }
};
