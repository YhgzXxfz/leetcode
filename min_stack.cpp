class MinStack {
private:
    stack<int> data;
    stack<int> minStack;
public:
    void push(int x) {
        data.push(x);
        if (minStack.empty() || x <= minStack.top()) minStack.push(x);
    }

    void pop() {
        if (data.empty() || minStack.empty()) return;
        int x = data.top();
        data.pop();
        if (x == minStack.top()) minStack.pop();
    }

    int top() {
        if (data.empty() || minStack.empty()) return 0;
        return data.top();
    }

    int getMin() {
        if (data.empty() || minStack.empty()) return 0;
        return minStack.top();
    }
};
