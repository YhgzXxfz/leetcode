class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int sum = 0;
        for (auto c : ops) {
            if (c == "C") {
                int top = s.top();
                s.pop();
                sum -= top;
            } else if (c == "D") {
                int top = s.top();
                int curr = 2*top;
                s.push(curr);
                sum += curr;
            } else if (c == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                int curr = a+b;
                s.push(a);
                s.push(curr);
                sum += curr;
            } else {
                int curr = stoi(c);
                s.push(curr);
                sum += curr;
            }
        }
        return sum;
    }
};
