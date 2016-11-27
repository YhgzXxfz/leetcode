class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        const char * str = s.c_str();
        
        while (*str != '\0') {
            if ('(' == *str || '[' == *str || '{' == *str) left.push(*str);
            else {
                if (left.empty()) return false;
                
                char expected;
                switch(*str) {
                    case ')': 
                        expected = '(';
                        break;
                    case ']': 
                        expected = '[';
                        break;
                    case '}': 
                        expected = '{';
                        break;
                }
                
                if (left.top() != expected) return false;
                left.pop();
            }
            ++str;
        }
        return left.empty();
    }
};
