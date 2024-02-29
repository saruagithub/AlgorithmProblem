#include <vector>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

// 2023 year, 输出字符串s中包含的所有整数的最小和
// 整数就直接相加，负数就凑到最长 减
// eg, b12-24aA1C79-3A
int sumMin(string s) {
    int sum = 0;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            i++;
            int begin = i;
            string sub;
            while(i < s.size() && isdigit(s[i])) i++;
            sub = s.substr(begin, i - begin);
            sum -= stoi(sub);
        }
        else if (isdigit(s[i])) {
            sum += (s[i] - '0');
        }
    }
    return sum;
}

int main() {
    //string ss = "b12-24aA1C79-3A"; // -7
    string ss = "b12-34aAA"; // -7
    cout << sumMin(ss) << endl;
    return 0;
}