class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        
        string result;
        bool sign = num < 0 ? true : false;
        
        num = abs(num);
        while (num) {
            result += to_string(num%7);
            num /= 7;
        }
        reverse(result.begin(), result.end());
        return sign ? "-"+result : result;
    }
};
