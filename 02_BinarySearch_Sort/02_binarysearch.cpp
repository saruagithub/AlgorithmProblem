//
//  04_binarysearch.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/10/3.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

//naive binary search
long int binarySearch_basic(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    long int start = 0, end = nums.size() - 1, mid = 0;
    while (start <= end) {
        mid = start + ((end - start) >> 1);
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) {
            end = mid - 1;
        }
        else start = mid + 1;
    }
    return -1;
}

// 二分查找第一个目标元素，左边界, 第一个大于等于target的数, case 0 0 0 1(target) 1 1 2
int binarySearch_left(vector<int>& numbers, int target){
    if (numbers.size() <= 0) return -1;
    int start = 0, end = numbers.size() - 1, mid = 0;
    int res = -1;
    while (start <= end) {
        mid = start + ((end - start) >> 1);
        if (numbers[mid] >= target) {
            res = mid;
            end = mid - 1; // maybe ans, do not jump
        } else {
            start = mid + 1;
        }
    }
    return res; //直接返回start可能为0 (target=-1)，6(target=4), 5(target=3)
}

// 二分查找第一个目标元素，左边界, 第一个大于等于target的数, case 0 0 0 1(target) 1 1 2
int binarySearch_left1(vector<int>& numbers, int target){
    if (numbers.size() <= 0) return -1;
    int start = 0, end = numbers.size() - 1, mid = 0;
    while (start <= end) {
        mid = start + ((end - start) >> 1);
        if (numbers[mid] >= target) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return end; //直接返回start可能为0 (target=-1)，6(target=4), 5(target=3)
}

// 二分查找最后一个目标元素，test case vector<int> data = {0,1,1,1,1 (target),3}
int binarySearch_right(vector<int>& numbers, int target){
    if (numbers.size() <= 0) return -1;
    int start = 0, end = numbers.size() - 1, mid = 0;
    int res = -1;
    while (start <= end) {
        mid = start + ((end - start) >> 1);
        if (numbers[mid] <= target) {
            res = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return res;
    //return start; //直接返回start可能为0(target=-1)，5(target=4),4(target=3)
}

int binarySearch_right1(vector<int>& numbers, int target){
    if (numbers.size() <= 0) return -1;
    int start = 0, end = numbers.size() - 1, mid = 0;
    int res = -1;
    while (start <= end) {
        mid = start + ((end - start) >> 1);
        if (numbers[mid] <= target) {
            res = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return res;
    //return start; //直接返回start可能为0(target=-1)，5(target=4),4(target=3)
}

void test_binary_search() {
    vector<int> data = {0, 1, 2, 3, 3, 4, 4, 7};
    int target = 3;
    cout << binarySearch_basic(data,target) << endl;
    cout << endl;
    cout << binarySearch_left(data,target) << endl;
    cout << endl;
    cout << binarySearch_right(data,target) << endl;
    //cout << endl;
    //cout << binarySearch_hz_right(data,target) << endl;
}

// clang++ -std=c++14 04_binarysearch.cpp -o 04_binarysearch
int main() {
    test_binary_search();
    return 0;
}
