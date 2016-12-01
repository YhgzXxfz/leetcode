class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        tail.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        moveTailToHead();
        if (!head.empty()) head.pop();
    }

    // Get the front element.
    int peek(void) {
        moveTailToHead();
        if (!head.empty()) return head.top();
        return 0;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return head.empty() && tail.empty();
    }
    
private:
    void moveTailToHead() {
        if (head.empty()) {
            while (!tail.empty()) {
                int element = tail.top();
                tail.pop();
                head.push(element);
            }
        }
    }
    
    stack<int> head, tail;
};
