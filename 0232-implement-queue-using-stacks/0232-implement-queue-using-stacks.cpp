#include<stack>
class MyQueue {
private:
    stack<int> s;
public:
    MyQueue() {
        
    }
    void insertAtBottom(int x) {
        if (s.empty()) {
            s.push(x);
            return;
        }

        int temp = s.top();
        s.pop();
        insertAtBottom(x);
        s.push(temp);
    }
    
    void push(int x) {
        insertAtBottom(x);
    }
    
    int pop() {
        int val = s.top();
        s.pop();
        return val;
    }
    
    int peek() {
        int val = s.top();
        return val;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */