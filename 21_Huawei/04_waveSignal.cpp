#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 00101010101100001010010,  01010
// 111010, 010
int main() {
    // 00101010101100001010010 , 01010
    string input;
    cin >> input;
    int left = 0, right = 0, maxlen = 0;
    for(int i = 0; i < input.size(); i++) {
        int l, r = 0;
        l = i;
        //cout << l << endl;
        bool flag = 0;
        while (i < input.size() && (input[i] - '0') == flag) {
            flag = !flag;
            i++;
        }
        if (l + 1 == i) {
            i--;
            continue;
        }

        if (input[i - 1] == '0') r = i;
        else r = i - 1;
        if (r > l && r - l > maxlen) {
            left = l;
            right = r;
        }
    }
    cout << input.substr(left, right - left) << endl;
    return 0;
}