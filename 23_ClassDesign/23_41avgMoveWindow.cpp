#include "../21_Huawei/21_header.h"

class MovingAverage {
public:
    /** Initialize your data structure here. */
    double sum;
    queue<int> que;
    int size;

    MovingAverage(int size) : sum(0), size(size) {

    }
    
    double next(int val) {
        que.push(val);
        sum += val;
        if (que.size() > size) {
            sum -= que.front();
            que.pop();
        }
        return sum / que.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */