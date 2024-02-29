//
//  main.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/2.
//  Copyright © 2020 wangxue. All rights reserved.
//

#include <iostream>
using namespace std;

//在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
//数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
//请找出数组中任意一个重复的数字。
int repeatedNum(int *array, int len){
    if (len <= 0) {
        return -1;
    }
    for (int i=0; i<len; i++) {
        //exchange
        while (array[i] != i) {
            if(array[i] == array[array[i]]) return array[i];
            else swap(array[i],array[array[i]]);
        }
    }
    return -1;
}

int main_repeatedNum() {
    // insert code here...
    int array[7] = {2,3,1,0,2,5,3};
    cout << repeatedNum(array, 7) <<endl;
    return 0;
}
