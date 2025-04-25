class MyQueue {
public:
    stack<int> enqueue; // temp stack
    stack<int> dequeue; // always holds the queue in correct order

    MyQueue() {}

    void push(int x) {
        // Move all elements from dequeue to enqueue
        while (!dequeue.empty()) {
            enqueue.push(dequeue.top());
            dequeue.pop();
        }

        dequeue.push(x);

        while (!enqueue.empty()) {
            dequeue.push(enqueue.top());
            enqueue.pop();
        }
    }

    int pop() {
        int val = dequeue.top();
        dequeue.pop();
        return val;
    }

    int peek() {
        return dequeue.top();
    }

    bool empty() {
        return dequeue.empty();
    }
};
