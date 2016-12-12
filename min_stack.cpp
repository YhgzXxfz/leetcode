class MinStack {
public:
    void push(int x) {
        data.push(x);
        if (minStack.empty() || x <= minStack.top()) minStack.push(x);
    }

    void pop() {
        if (data.empty()) return;
        int x = data.top();
        data.pop();
        if (x == minStack.top()) minStack.pop();
    }

    int top() {
        if (data.empty()) return 0;
        return data.top();
    }

    int getMin() {
        if (minStack.empty()) return 0;
        return minStack.top();
    }
    
private:
    stack<int> data;
    stack<int> minStack;
};
