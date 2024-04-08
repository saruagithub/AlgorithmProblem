#include "21_header.h"
int main() {
    int N, i = 0; // hours
    cin >> N;
    int m;
    cin >> m;
    vector<int> minValue(N + 1, INT_MAX);

    while (i < m) {
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        for (int j = stoi(s1); j <= stoi(s2); j++) {
            minValue[j] = min(minValue[j], stoi(s3));
        }
        i++;
    }
    int res = 0;
    for (int i = 1; i <= N; i++) {
        res += minValue[i];
    }
    cout << res << endl;
    return 0;
}