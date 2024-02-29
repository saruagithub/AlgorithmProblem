#include <vector>
using namespace std;

// 循环队列，每次在r插入，在l删除
// size 控制大小
class MyCircularQueue {
public:
    vector<int> arr;
    int l, r, size, limit;
    MyCircularQueue(int k) {
        arr.resize(k);
        l = r = size = 0;
        limit = k;
    }
    
    bool enQueue(int value) {
        if (size == limit) return false;
        arr[r] = value;
        r = r == limit - 1? 0 : (r + 1);
        size++;
        return true;
    }
    
    bool deQueue() {
        if (size == 0) return false;
        l = l == limit - 1? 0 : (l + 1);
        size--;
        return true;
    }
    
    int Front() {
        if (size == 0) return -1;
        return arr[l];
    }
    
    int Rear() {
        if (size == 0) return -1;
        int last = (r == 0)? (limit - 1) : (r - 1);
        return arr[last];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == limit;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */