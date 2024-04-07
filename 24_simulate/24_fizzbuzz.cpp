#include <vector>
#include <string>

vector<string> fizzBuzz(int n) {
    // 3 * 1   3 * 2
    // 3 * 5 * 1   3 * 5 * 2
    vector<string> res(n);
    for (int i = 1; i <= n ;i++) {
        res[i - 1] = to_string(i);
    }
    for (int i = 3; i <= n; i += 3) {
        res[i - 1] = "Fizz";
    }
    for (int i = 5; i <= n ; i += 5) {
        if (res[i - 1] == "Fizz") res[i - 1] += "Buzz";
        else res[i - 1] = "Buzz";
    }
    return res;
}