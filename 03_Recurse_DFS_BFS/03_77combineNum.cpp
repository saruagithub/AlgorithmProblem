#include <vector>
#include <iostream>
using namespace std;

// leecode 77
// 输入：n = 4, k = 2
// 输出：
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
vector<vector<int>> res;
void dfs(int n, int k, int start, vector<int>& path) {
    if (path.size() == k) {
        res.push_back(path);
        return;
    }
    // from 1 to n
    for (int i = start; i <= n; i++) {
        path.push_back(i);
        dfs(n, k, i+1, path);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    if (k <= 0 || n < k) return res;
    vector<int> path;
    dfs(n, k, 1, path);
    return res;
}