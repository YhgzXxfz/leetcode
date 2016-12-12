class Solution {
public:
    int calculate(string s) {
        int result = 0, num = 0;
        stack<int> signs;
        int sign = 1;
        signs.push(1);
        
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c-'0');
            } else if (c == '+' || c == '-') {
                result = result + signs.top() * sign * num;
                num = 0;
                sign = c == '+' ? 1 : -1;
            } else if (c == '(') {
                signs.push(signs.top() * sign);
                sign = 1;
            } else if (c == ')') {
                result = result + signs.top() * sign * num;
                signs.pop();
                num = 0;
                sign = 1;
            }
        }
        
        if (num) result = result + signs.top() * sign * num;
        
        return result;
    }
};
