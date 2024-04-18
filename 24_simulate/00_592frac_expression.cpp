#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;


// LCM (a, b) = (a * b) / GCD(a, b)
// 最小公倍数 = （a * b） / 最大公约数

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// 输入: expression = "-1 / 2 + 1 / 2"
// x1 / y1 + x2 / y2  = (x1 * y2 + x2 * y1) / (y1 * y2)
// 初始 x = 0, y = 1,  x = x * y1 + x1 * y,,  y = y * y1

string fractionAddition(string expression) {
    // lcm 最小公倍数， gcd最大公约数
    int num, num2 = 1, lcmnum = 1;
    stringstream ss(expression);
    vector<pair<int, int>> v;
    for (char ch; ss >> num >> ch >> num2; lcmnum = lcm(lcmnum, num2)) {
        cout << num << ch << num2  << " " << lcmnum << endl;
        v.emplace_back(num, num2);
    }
    //cout << "lcm = " << lcmnum << endl;
    // 分子求和
    num = accumulate(v.begin(), v.end(), 0, [lcmnum](int a, const auto& b) {
        return a + lcmnum / b.second * b.first;
    });
    num2 = gcd(num, lcmnum);
    //cout << " num = " << num << " num2=" << num2 << endl;
    return to_string(num / num2) + "/" + to_string(lcmnum / num2);
}

int main() {
    string exp = "1/3+1/2";
    cout << fractionAddition(exp);
    return 0;
}