#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> normalStk, minStk;
    MinStack() {}
    
    void push(int val) {
        normalStk.push(val);
        if (minStk.empty() || val < minStk.top()) minStk.push(val);
        else minStk.push(minStk.top());
    }
    
    void pop() {
        if (!normalStk.empty()) normalStk.pop();
        if (!minStk.empty()) minStk.pop();
    }
    
    int top() {
        return normalStk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */