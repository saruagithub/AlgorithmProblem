#include <iostream>
#include <vector>
using namespace std;

void swapnum(vector<int>& nums, int s, int t) {
    int origin = nums[s];
    nums[s] = nums[t];
    nums[t] = origin;
}

void merge(vector<int>& nums, int s1, int e1, int s2, int e2) {
    if (s1 < e1 || s2 < e2) return;
    if (nums[s1] < nums[s2]) {
        swapnum(nums, s1, s2);
        merge(nums, s1 + 1, e1, s2, e2);
    } else {
        merge(nums, s1, e1, s2 + 1, e2);
    }
}

void sort(vector<int>& nums) {
    int l = 0, r = nums.size();
    int mid = (l + r) >> 1;
    merge(nums, l, mid, mid + 1, r - 1);
}

int main() {
    vector<int> nums = {4, 2, 1, 3};
    cout << "before sort: " << endl;
    for (int num : nums) {
        cout << num << ",";
    }
    sort(nums);
    cout << "after sort: " << endl;
    for (int num : nums) {
        cout << num << ",";
    }
    return 0;
}