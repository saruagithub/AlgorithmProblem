#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

static int where = 0;

int compute(vector<int>& numbers, vector<char>& ops) {
    int n = numbers.size();
    int ans = numbers[0];
    for (int i = 1; i < n; i++) {
        ans += ops[i-1]=='+'? numbers[i] : -numbers[i];
    }
    return ans;
}

int fun(string &s, int i) {
    int cur = 0;
    vector<int> numbers;
    vector<char> ope;
    // s[i...] 开始计算，遇到字符串终止，遇到)停止
    // 返回 自己负责的这段的计算结果
    while (i < s.size() && s[i] != ')') {
        if (s[i] == ' ') {
            i++;
            continue;
        }
        else if (s[i] >= '0' && s[i] <='9') {
            cur = cur * 10 + (s[i] - '0');
            i++;
        } else if (s[i] != '(') { // operator
            //push(number, ope, cur, s[i++]); // push into stack
            numbers.push_back(cur);
            ope.push_back(s[i]);
            i++;
            cur = 0;
        } else { // is '('
            cur = fun(s, i+1);
            i = where + 1;
        }
    }
    // final number
    numbers.push_back(cur);
    ope.push_back('+');
    where = i;
    return compute(numbers, ope);
}

int calculate(string& s) {
    // stack, ( enter, ) calculate
    int res = 0;
    res = fun(s, 0);
    return res;
}

int main() {
    //string s = "(1+(4+5+2)-3)+(6+8)";
    string s = "  30";
    cout << fun(s, 0) << endl;
    return 0;
}

// stack sign, save the operator
int calculate(string s) {
    stack<int> ops;
    ops.push(1); // operator
    int sign = 1;

    int ret = 0;
    int n = s.length();
    int i = 0;
    while (i < n) {
        if (s[i] == ' ') {
            i++;
        } else if (s[i] == '+') {
            sign = ops.top();
            i++;
        } else if (s[i] == '-') {
            sign = -ops.top();
            i++;
        } else if (s[i] == '(') {
            ops.push(sign);
            i++;
        } else if (s[i] == ')') {
            ops.pop();
            i++;
        } else {
            long num = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                i++;
            }
            ret += sign * num;
        }
    }
    return ret;
}