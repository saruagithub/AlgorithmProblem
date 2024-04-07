
#include <string>
#include <iostream>
using namespace std;

bool backspaceCompare(string S, string T) {
    int i = S.length() - 1, j = T.length() - 1;
    int skipS = 0, skipT = 0;

    while (i >= 0 || j >= 0) {
        while (i >= 0) {
            if (S[i] == '#') {
                skipS++, i--;
            } else if (skipS > 0) {
                skipS--, i--;
            } else {
                break;
            }
        }
        while (j >= 0) {
            if (T[j] == '#') {
                skipT++, j--;
            } else if (skipT > 0) {
                skipT--, j--;
            } else {
                break;
            }
        }
        if (i >= 0 && j >= 0) {
            if (S[i] != T[j]) {
                return false;
            }
        } else {
            if (i >= 0 || j >= 0) {
                return false;
            }
        }
        i--, j--;
    }
    return true;
}

bool backspaceCompare1(string s, string t) {
    string ss, tt;
    for (char cha : s) {
        if (cha != '#') {
            ss += cha;
        } else {
            if (!ss.empty()) ss.pop_back();
            continue;
        }
    }
    for (char cha : t) {
        if (cha != '#') {
            tt += cha;
        } else {
            if (!tt.empty()) tt.pop_back();
            continue;
        }
    }
    return ss == tt;
}

int main() {
    cout << backspaceCompare1("ab#c", "ad#c");
    return 0;
}