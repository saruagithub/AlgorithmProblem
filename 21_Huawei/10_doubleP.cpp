#include <algorithm>
#include "21_header.h"
using namespace std;

// 数组中是否存在重复元素
// 数组中的子数组和
// 排序数组中是否存在重复元素
// 链表有环吗
// 链表排序

// eg 1,3,5,7,2  sum = 9, ans = 3 (1,3,5)
int maxlenOfSum(vector<int>& numbers, int sum) {
    int left = 0;
    int right = 0;
    int tempsum = numbers[left];
    int res = 0;
    while (right < numbers.size()) {
        if (tempsum < sum) {
            right++;
            if (right == numbers.size()) break;
            tempsum += numbers[right];
        } else if (tempsum > sum) {
            tempsum -= numbers[left];
            left++;
        } else {
            res = std::max(res, right - left + 1);
            tempsum -= numbers[left];
            left++;
        }
    }
    return res;
}

int main() {
    string input;
    cin >> input;
    vector<int> numbers = splitstr(input, ',');
    int n;
    cin >> n;
    cout << maxlenOfSum(numbers, n);
    return 0;
}