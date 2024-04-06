#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

// 输入：num1 = "11", num2 = "123"
// 输出："134"
string addStrings(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int len = max(num1.size(), num2.size());
    int n = std::abs(int(num2.size() - num1.size()));
    for (int i = 0; i < n; i++) {
        if (num1.size() < num2.size()) num1 += '0';
        else num2 += '0';
    }

    // add two
    string res(len + 1, '0');
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int tmp = (num1[i] - '0') + (num2[i] - '0') + carry;
        carry = tmp / 10;
        res[i] = (tmp % 10 + '0');
    }
    if (carry == 1) res[len] = '1';
    else res = res.substr(0, len);
    reverse(res.begin(), res.end());
    return res;
}

string multiply(string num1, string num2) {
    string res = "0";
    if (num1 == "0" || num2 == "0") return res;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for(int i = 0; i < num2.size(); i++) {
        string tmp = "";
        int carry = 0;
        for(int j = 0; j < num1.size(); j++) {
            int mul = (num1[j] - '0') * (num2[i] - '0') + carry;
            carry = mul / 10;
            tmp += (mul % 10) + '0';
        }
        if (carry > 0) {
            tmp += (carry + '0');
            carry = 0;
        }
        //cout << "i = tmp = " << i << " " << tmp << endl;
        reverse(tmp.begin(), tmp.end());
        for (int k = 0; k < i; k++) tmp += '0';
        res = addStrings(tmp, res);
    }
    return res;
}

int main() {
    cout << addStrings("12","99") << endl;
    cout << multiply("12","99") << endl;
    return 0;
}