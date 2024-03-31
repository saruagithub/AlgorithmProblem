#include "21_header.h"

int minColor(vector<int>& numbers) {
    vector<int> res;
    sort(numbers.begin(), numbers.end());
    res.push_back(numbers[0]);
    int left = 1;
    while (left < numbers.size()) {
        bool divided = false;
        for (auto div : res) {
            if (numbers[left] % div == 0) {
                divided = true;
                break;
            }
        }
        if (!divided) {
            res.push_back(numbers[left]);
        }
        left++;
    }
    return res.size();
}

int main() {
    string ss;
    getline(cin, ss);
    vector<int> numbers;
    numbers = splitstr(ss, ' ');
    cout << minColor(numbers) << endl;
    return 0;
}
