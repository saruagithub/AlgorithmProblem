#include <vector>
#include <unordered_map>
using namespace std;

int getWinner(vector<int>& arr, int k) {
    int allmax = 0;
    if (k > arr.size()) {
        for (int i = 0; i < arr.size(); i++) {
            allmax = max(allmax, arr[i]);
        }
        return allmax;
    }

    int cur = 0;
    unordered_map<int, int> mp; // win num, times
    while (true) {
        int num = max(arr[cur], arr[cur + 1]);
        if (!mp.count(num)) {
            mp[num] = 1;
            if (k == 1) return num;
        }
        else if (mp[num] + 1 >= k) {
            return num;
        } else {
            mp[num] += 1;
        }
        // change arr
        if (arr[cur] > arr[cur + 1]) {
            arr.push_back(arr[cur + 1]);
            arr[cur + 1] = arr[cur];
        } else {
            arr.push_back(arr[cur]);
        }
        cur++;
        if (cur > arr.size()) return allmax;
    }
    return -1;
}

int getWinner(vector<int>& arr, int k) {
    int winner = max(arr[0],arr[1]);
    int cnt = 1;
    if (k == 1) return winner;
    for (int i = 2; i < arr.size(); i++) {
        if (arr[i] > winner) {
            winner = arr[i];
            cnt = 1;
        }
        else {
            if(++cnt == k) return winner;
        }
    }
    return winner;
}