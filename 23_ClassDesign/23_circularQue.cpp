#include <vector>

class MyCircularQueue {
public:
    int l, r, size, capacity;
    vector<int> arr;

    MyCircularQueue(int k) {
        arr.resize(k);
        l = r = size = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if (size == capacity) return false;
        arr[r] = value;
        if (r == capacity - 1) r = 0;
        else r++;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (size == 0) return false;
        if (l == capacity - 1) l = 0;
        else l++;
        size--;
        return true;
    }
    
    int Front() {
        if (size == 0) return -1;
        return arr[l];
    }
    
    int Rear() {
        if (size == 0) return -1;
        int last = (r == 0)? (capacity - 1) : (r - 1);
        return arr[last];  
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    bool isFull() {
        return (size == capacity);
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