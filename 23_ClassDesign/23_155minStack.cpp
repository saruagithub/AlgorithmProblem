#include "../21_Huawei/21_header.h"

// leecode155
// 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
class MinStack {
public:

    stack<int> valstk;
    stack<int> minstk; // 每次都存最小的值
    MinStack() {
    }
    
    void push(int val) {
        valstk.push(val);
        if (minstk.empty()){
            minstk.push(val);
            return;
        }
        if (minstk.top() <= val) {
            minstk.push(minstk.top());
        } else {
            minstk.push(val);
        }
        return;
    }
    
    void pop() {
        valstk.pop();
        minstk.pop();
    }
    
    int top() {
        return valstk.top();
    }
    
    int getMin() {
        return minstk.top();
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