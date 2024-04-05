#include <stack>

class MyQueue {
public:

    stack<int> stk_in; // help
    stack<int> stk_out;
    MyQueue() {
    }
    
    void push(int x) {
        // 1 2 // push into stk_out
        while (!stk_out.empty()) {
            int head = stk_out.top();
            stk_out.pop();
            stk_in.push(head);
        }
        stk_out.push(x);
        while (!stk_in.empty()) {
            int head = stk_in.top();
            stk_in.pop();
            stk_out.push(head);
        }
        // stk_in.push(x);
    }
    
    int pop() {
        int res = stk_out.top();
        stk_out.pop();
        return res;
    }
    
    int peek() {
        return stk_out.top();
    }
    
    bool empty() {
        return stk_out.empty();
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