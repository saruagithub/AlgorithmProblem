//
//  01_towsum.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/5.
//

#include <iostream>
using namespace std;

//对于有符号整数，每一次右移操作，高位补充的是1；
//对于无符号整数，每一次右移操作，高位补充的则是0
//按位与:&, 按位或:|, 按位异或:^, 左移:<<, 右移:>>, 取反:~
int add(int a, int b){
    int sum, carry;
    while (b!=0) {
        // 异或操作得无进位和
        sum = a^b;
        // 与操作后移位得进位值
        carry = ((unsigned int) (a & b) << 1);
        // 循环，直到进位为0
        a = sum;
        b = carry;
    }
    return a;
}

int main() {
    cout << add(5,6) << endl;
    return 0;
}
