#include <queue>

class MyStack {
public:
    queue<int> mstk;
    queue<int> help;

    MyStack() {

    }
    
    void push(int x) {
        while (!mstk.empty()) {
            int tmp = mstk.front();
            mstk.pop();
            help.push(tmp);
        }
        mstk.push(x);
        while(!help.empty()) {
            int tmp = help.front();
            help.pop();
            mstk.push(tmp);
        }
    }
    
    int pop() {
        int tmp = mstk.front();
        mstk.pop();
        return tmp;
    }
    
    int top() {
        return mstk.front();
    }
    
    bool empty() {
        return mstk.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */