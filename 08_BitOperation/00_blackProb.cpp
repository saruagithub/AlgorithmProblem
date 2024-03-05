#include <iostream>
using namespace std;

// 异或运算就是无进位相加, 丢弃进位; 满足交换律 结合律 （同一批数字异或得到的结果是一样的）
// 1110 ^ 1101   0 0 1 1 
// 0 ^ n = n,  n ^ n = 0
// a ^ b = c, a = c ^ b, b = c ^ a  都可以得到

// 题目 a白b黑在袋子里，拿出2个同为白/黑 -> 放1白， 1白1黑 放1黑，最终球是黑的概率
// 看成 00 -> 0, 11 -> 0  ||  0,1 -> 1 就类似异或操作，相当于a个0 b个1 整体异或起来结果是啥
int blackProba(int a, int b) {
    if (b % 2 == 0) return 0;
    else return 1; // 奇数个黑球，最后一个肯定是黑球
}

void exchangeTwo(int a, int b) {
    cout << a << " " << b << endl;
    a = a ^ b;
    b = a ^ b; // n ^ n = 0
    a = a ^ b;
    cout << a << " " << b << endl;
}

int main() {
    int a = 5, b = 6;
    exchangeTwo(a, b);
    return 0;
}