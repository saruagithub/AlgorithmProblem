#include <iostream>
using namespace std;

int drink(int n) {
    int res = 0, tmp = 0;
    while (n >= 3) {
        res += n / 3;
        tmp = n % 3;
        n = n / 3 + tmp;
    }
    return (n == 2) ? res+1 : res;
}

int main() {
    int arr[6] = {3, 10, 11, 12, 14, 81};
    for (int i = 0; i < 6; i++) {
        cout << drink(arr[i]) << endl;
    }
    return 0;
}