//
//  05_sort.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/11/18.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

static void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void selectSort(vector<int>& nums) {
    for (int i = 0, minIndex; i < nums.size() - 1; i++) {
        minIndex = i;
        // selec the min, put into the start
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[minIndex]) minIndex = j;
        }
        swap(nums, i, minIndex);
    }
}

void bubbleSort(vector<int>& nums) {
    // exchange bigger elem to the tail
    for (int end = nums.size() - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (nums[i] > nums[i+1]) swap(nums, i, i+1);
        }
    }
}

void insertSort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        // 0 - i-1 有序了，新来的数是i，向左看
        // 把小的往前放
        for (int j = i - 1; j >=0 && nums[j] > nums[j+1]; j--) {
            swap(nums, j, j+1);
        }
    }
}

int main() {
    vector<int> nums = {2,3,1,4,5};
    // selectSort(nums);
    bubbleSort(nums);
    for(auto ele: nums) cout << ele << " ";
    return 0;
}

int test_bubsort() {
    int n = 10;
    int numbers[10];
    int i;

    // 读入给定的数字
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    for (i = 0; i < n; i++) {
        for ( int j = 0; j < n - 1 - i; j++) {
            if (numbers[j] < numbers[j+1]) {
                int temp;
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d", numbers[i]);
    }
    return 0;
}
