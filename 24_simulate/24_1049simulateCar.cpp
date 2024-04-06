#include <vector>

bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> gocar(1001,0);
    vector<int> downcar(1001,0);
    int curpass = 0;
    for (auto trip : trips) {
        // in trip[1] go car
        gocar[trip[1]] += trip[0];
        // down car
        downcar[trip[2]] += trip[0];
    }
    for (int i = 0; i < 1001; i++) {
        curpass += gocar[i];
        curpass -= downcar[i];
        if (curpass > capacity) return false;
    }
    return true;
}