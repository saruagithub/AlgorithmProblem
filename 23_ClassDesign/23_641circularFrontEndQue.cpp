#include "../21_Huawei/21_header.h"

// 设计实现双端队列。
// 实现 MyCircularDeque 类:
// MyCircularDeque(int k) ：构造函数,双端队列最大为 k 。
// boolean insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true ，否则返回 false 。
// boolean insertLast() ：将一个元素添加到双端队列尾部。如果操作成功返回 true ，否则返回 false 。
// boolean deleteFront() ：从双端队列头部删除一个元素。 如果操作成功返回 true ，否则返回 false 。
// boolean deleteLast() ：从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 false 。
// int getFront() )：从双端队列头部获得一个元素。如果双端队列为空，返回 -1 。
// int getRear() ：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1 。
// boolean isEmpty() ：若双端队列为空，则返回 true ，否则返回 false  。
// boolean isFull() ：若双端队列满了，则返回 true ，否则返回 false 。

class MyCircularDeque {
public:
    int l, r, size, capacity;
    vector<int> arr;

    MyCircularDeque(int k) {
        capacity = k;
        l = size = 0;
        r = capacity == 1 ? 0 : l + 1; // special casel + 1;
        arr.resize(capacity);
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        cout << "l = " << l  << endl;
        arr[l] = value;
        l = (l - 1 + capacity) % capacity;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        cout << "r = " << r  << endl;
        arr[r] = value;
        r = (r + 1) % capacity;
        cout << "r = " << r  << endl;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        //cout << "l = " << l  << endl;
        //arr[l] = -1;
        l = (l + 1) % capacity;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        //cout << "r = " << r << endl;
        //arr[r] = -1;
        r = (r - 1 + capacity) % capacity;
        size--;
        return true;
    }
    
    int getFront() {
        // notice, l is the location to save value
        //cout << "front l = " << l  << endl;
        if (isEmpty()) return -1;
        return arr[(l + 1) % capacity];
    }
    
    int getRear() {
        //cout << "rear r = " << r << endl;
        if (isEmpty()) return -1;
        return arr[(r - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */