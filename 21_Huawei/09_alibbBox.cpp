#include "21_header.h"

int alibbBox(vector<int>& numbers) {
    int sum = 0;
    for (auto num: numbers) {
        sum += num;
    }
    int left_sum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (left_sum == (sum - numbers[i])) return i;
        else {
            left_sum += numbers[i];
            sum -= numbers[i];
        }
    }
    return -1;
}

int main() {
    string input;
    cin >> input;
    vector<int> numbers = splitstr(input, ',');
    cout << alibbBox(numbers) << endl;
    return 0;
}