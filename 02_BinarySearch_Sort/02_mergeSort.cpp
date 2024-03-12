#include <vector>
#include <iostream>
using namespace std;

// base case
int fun(vector<int> arr, int l, int r) {
		if (l == r) return arr[l];
		int m = (l + r) / 2;
		int lmax = fun(arr, l, m);
		int rmax = fun(arr, m+1, r);
		return max(lmax, rmax);
}

// 求数组里的最大值，递归版，多画递归调用图
// T(n) = 2 * T(N / 2) + O(1)
int maxval(vector<int> arr) {
    return fun(arr, 0, arr.size() - 1);
}

void test() {
    vector<int> nums = {2,5,1};
    cout << maxval(nums);
}

// ---------------------------------------
int numbers[50];
int help[50] = {0};

// a-> 2 3 3 , b-> 4 6 6 ,  按顺序存入 help[i]
void merge(int l, int m, int r) {
    int i = l;
    int p1 = l;
    int p2 = m;
    while (p1 <= m && p2 <= r) {
        help[i++] = numbers[p1] <= numbers[p2]? numbers[p1++] : numbers[p2++];
    }
    // only one execute
    while (p1 <= m) help[i++] = numbers[p1++];
    while (p2 <= r) help[i++] = numbers[p2++];

    for (i = l; i <= r; i++) {
        numbers[i] = help[i]; // put back
    }
}

// 时间复杂度 O(n logn)  ,space O(n)
void mergeSort(int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    mergeSort(l, m);
    mergeSort(m+1, r);
    merge(l, m+1, r);
}

int main() {
    int n, i = 0, temp = 0;
    cin >> n;
    while (i < n) {
        cin >> temp;
        numbers[i] = temp;
        i++;
    }
    mergeSort(0, n-1);
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << ",";
    }
}