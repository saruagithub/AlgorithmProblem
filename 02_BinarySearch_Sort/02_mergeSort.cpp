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

// ---------------------------------------------------------
// ---------------------------------------------------------

int numbers[50];
int help[50] = {0};

// p1-> 2 1 , p2-> 4 3 ,  按顺序存入 help[i]
// l, m, r is index of numbers
void merge(int l, int m, int r) {
    int i = l;
    int p1 = l;
    int p2 = m + 1;
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
// T(n) = 2 * T(n/2) + O(n)
void mergeSort(int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    mergeSort(l, m);
    mergeSort(m+1, r);
    merge(l, m, r);
}

// 非递归版本的归并排序，步长step 1， 2， 4, 8 。。。 直到＞ numbers.size()
void mergeSort1(int len) {
    int step = 1;
    for (; step < len; step <<= 1) {
        int l = 0, m , r;
        while (l < len) {
            m = l + step - 1;
            if (m + 1 >= len) break; // 右侧开头都为0了，不需要merge
            r = min(l + 2 * step - 1, len - 1);
            //cout << "r = " << r << " ";
            merge(l, m, r);
            l = r + 1;
        }
    }
}

int main() {
    int n, i = 0, temp = 0;
    // 自己输入数据大小n个，输入numbers数组
    cin >> n;
    while (i < n) {
        cin >> temp;
        numbers[i] = temp;
        i++;
    }
    mergeSort(0, n-1);
    //mergeSort1(n);
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << ",";
    }
}