class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        for (auto token : tokens) {
            if (isOperator(token)) {
                int a = operands.top(); operands.pop();
                int b = operands.top(); operands.pop();
                operands.push(calculate(b, a, token));
            } else {
                operands.push(stoi(token));
            }
        }
        return operands.top();
    }

private:
    bool isOperator(string token) {
        return token.size() == 1 && string("+-*/").find(token) != string::npos;
    }

    int calculate(int a, int b, string token) {
        if (token == "+") return a+b;
        if (token == "-") return a-b;
        if (token == "*") return a*b;
        if (token == "/") return a/b;
        return 0;
    }

    stack<int> operands;
};
