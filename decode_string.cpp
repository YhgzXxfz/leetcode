class Solution {
public:
    string decodeString(string s) {
        string tmp;
        stack<int> numStack;
        stack<string> strStack;
        int n = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]))
                n = n * 10 + s[i] - '0';
            else if (s[i] == '[') {
                numStack.push(n);
                n = 0;
                strStack.push(tmp);
                tmp.clear();
            }
            else if (s[i] == ']') {
                int k = numStack.top();
                numStack.pop();
                for (; k > 0; k--)
                    strStack.top() += tmp;
                tmp = strStack.top();
                strStack.pop();
            }
            else
                tmp += s[i];
        }
        return strStack.size() == 0 ? tmp : strStack.top();
    }
};
