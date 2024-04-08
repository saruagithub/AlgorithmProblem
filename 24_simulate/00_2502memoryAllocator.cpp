//leecode2502
// 给你一个整数 n ，表示下标从 0 开始的内存数组的大小。所有内存单元开始都是空闲的。

// 请你设计一个具备以下功能的内存分配器：

// 分配 一块大小为 size 的连续空闲内存单元并赋 id mID 。
// 释放 给定 id mID 对应的所有内存单元。
// 注意：

// 多个块可以被分配到同一个 mID 。
// 你必须释放 mID 对应的所有内存单元，即便这些内存单元被分配在不同的块中。

#include <vector>
using namespace std;

class Allocator {
public:
    vector<int> arr;
    Allocator(int n) : arr(n, 0) {

    }
    
    int allocate(int size, int mID) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                if (i + size > arr.size()) return -1;
                int j = i;
                for (; j < arr.size() && j < i + size; j++) {
                    if (arr[j] != 0) break;
                }
                if (j - i < size) {
                    i = j;
                    continue;
                }
                // find a space, allocate from i
                for (int k = i; k < arr.size() && k < i + size; k++) {
                    arr[k] = mID;
                }
                return i;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int num = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == mID) {
                num++;
                arr[i] = 0;
            }
        }
        return num;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */