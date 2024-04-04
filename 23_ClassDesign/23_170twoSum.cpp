#include "../21_Huawei/21_header.h"

class TwoSum {
public:
    unordered_map<long, int> times;
    TwoSum() {

    }
    
    void add(long number) {
        if (!times.count(number)) times[number] = 1;
        else times[number]++;
    }
    
    bool find(long value) {
        for (auto &[k,v] : times) {
            long left = value - k;
            if (left != k) {
                if (times.count(left)) return true;
            } else {
                if (times[left] > 1) return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */