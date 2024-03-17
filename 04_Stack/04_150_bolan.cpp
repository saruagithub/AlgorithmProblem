#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。
// 平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
// 该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
int ston(string s) {
    int cur = 0;
    bool fushu = false;
    for(auto ch: s) {
        if (ch == '-') fushu = true;
        else cur = cur * 10 + (ch - '0');
    }
    return fushu == true? (0-cur) : cur;
}
int evalRPN(vector<string>& tokens) {
    stack<int> numbers;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] != "+" && 
            tokens[i] != "-" && 
            tokens[i] != "*" && 
            tokens[i] != "/") {
                numbers.push(ston(tokens[i]));
                continue;
            }
        int right = numbers.top();
        numbers.pop();
        int left = numbers.top();
        numbers.pop();
        if (tokens[i] == "+") {
            numbers.push(left+right);
        } else if (tokens[i] == "-") {
            numbers.push(left-right);
        } else if (tokens[i] == "*") {
            numbers.push(left*right);
        } else {
            numbers.push(left/right);
        }
    }
    return numbers.top();
}

// 简化
int evalRPN1(vector<string>& tokens) {
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            if (tokens[i] == "+") st.push(num2 + num1);
            if (tokens[i] == "-") st.push(num2 - num1);
            if (tokens[i] == "*") st.push(num2 * num1);
            if (tokens[i] == "/") st.push(num2 / num1);
        } else {
            st.push(stoi(tokens[i]));
        }
    }
    int result = st.top();
    st.pop();
    return result;
}

int main() {
    vector<string> tokens = {"3","-4","+"};
    cout << evalRPN(tokens);
    return 0;
}