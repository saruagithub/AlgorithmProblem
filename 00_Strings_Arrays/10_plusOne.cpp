//
//  10_plusOne.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/10/31.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

//leecode 66, plus one 数组最末尾元素+1，考虑进位
vector<int> plusOne(vector<int>& digits) {
    digits[digits.size()-1]++;
    for(size_t i = digits.size() -1 ; i>=0; i--){
        if(digits[i] == 10) {
            digits[i] = 0;
            if (i == 0){
                digits.insert(digits.begin(),1);
            } else {
                digits[i-1]++;
            }
        } else {
            break;
        }
    }
    return digits;
}
