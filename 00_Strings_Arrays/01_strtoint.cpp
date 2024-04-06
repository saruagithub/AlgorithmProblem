//
//  01_strtoint.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/5.
//

#include <iostream>
#include <vector>
using namespace std;

int strToInt(string str){
    int i = 0, flag = 1;
    long int res = 0;
    while(str[i] == ' ') i++;
    if (str[i] == '-') flag = -1;
    if (str[i] == '-' || str[i]== '+') i++;
    for(; i<str.size() && isdigit(str[i]); i++){
        res = res * 10 + (str[i]-'0');
        if(res >= INT_MAX && flag == 1) return INT_MAX;
        if(res > INT_MAX && flag == -1) return INT_MIN;
    }
    return flag * res;
}

