#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s1;
    char ch;
    int res = 0;
    getline(cin, s1); // read whole line

    if (isdigit(ch)) res++;  // tolower(s1[i]) 大写变小写
    return 0;
}