//
//  reverse_num.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/21.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int reverse(int x) {
    long long ans = 0;
    while (x) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    //注意越界
    if (ans < INT_MIN || ans > INT_MAX) return 0;
    return int(ans);
}


int str_times(string s){
    int value = 0;
    for(long int i=0; i<s.length(); i++){
        value += (pow(2,i) * (s[s.length() - 1 -i] - '0'));
        //cout<<s[i]<<" "<<value<<endl;
    }
    int count = 0;
    while (value!=1) {
        if(value%2 != 0){
            value++;
        }
        else{
            value/=2;
        }
        count++;
    }
    return count;
}


int main(){
    cout<<str_times("101")<<endl;
    return 0;
}
