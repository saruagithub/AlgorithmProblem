#include "../21_Huawei/21_header.h"

// 输入：s = "(abcd)"
// 输出："dcba"
// 输入：s = "(ed(et(oc))el)"
// 输出："leetcode"


string reverseParentheses(string s) {
    stack<char> stk;
    string res;
    for (char ch: s) {
        if (ch != ')') stk.push(ch);
        else {
            string tmp = "";
            while (stk.top() != '(') {
                tmp += stk.top();
                stk.pop();
            }
            stk.pop(); // pop (
            for (char chr : tmp) {
                stk.push(chr);
            }
        }
    }
    if (stk.size() <= 0) return res;
    while (stk.size() != 0) {
        res += stk.top();
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string sss = "(u(love)i)";
    cout << reverseParentheses(sss) << endl;
}