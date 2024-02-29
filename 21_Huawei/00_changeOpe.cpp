#include <iostream>
#include <vector>
using namespace std;

// int 2.1 * 10^9
int main() {
    int N, a;
    int i = 0, bigger = 0, mul_index = -1, res = 0;
    cin >> N;
    vector<int> arr;
    while (cin >> a && i < N) { // 注意 while 处理多个 case
        arr.push_back(a);
        if (i > 0 && (arr[i] + arr[i - 1]) < (arr[i] * arr[i - 1]) && arr[i] * arr[i - 1] > bigger) {
            mul_index = i - 1;
            bigger = arr[i] * arr[i - 1];
        }
        i++;
    }
    for (int i = 0; i < N; i++) {
        if (i == mul_index) {
            res += bigger;
            i += 2;
        }
        res += arr[i];
    }
    cout << res;
}
// 64 位输出请用 printf("%lld")