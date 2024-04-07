#include <string>
#include <vector>

int minLength(string s) {
    vector<char> res;
    for (char ch : s) {
        if (!res.empty() && ((res.back() == 'A' && ch == 'B') || (res.back() == 'C' && ch == 'D'))) {
            res.pop_back();
        }
        else res.push_back(ch);
    }
    return res.size();
}