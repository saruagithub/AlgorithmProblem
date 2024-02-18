#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct point {
    int val, x, y;
    point(int val, int x, int y) : val(val), x(x), y(y) {}
};

// 传入函数对象
struct cmp {
    bool operator() (point &a, point &b) {
        return a.val > b.val;
    }
};

bool cmp1(point &a, point &b) {
    return a.val > b.val;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    // time O(k longn), space O(n)
    
    priority_queue<point, vector<point>, cmp> que;
    // priority_queue<point, vector<point>, decltype(&cmp1)> que(cmp1);

    // 传入函数指针, -std=C++2a
    // auto cmp2 = [](point &a, point &b)->bool {
    //     return a.val > b.val;
    // };
    // priority_queue<point, vector<point>, decltype(cmp2)> que;

    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        point temp1(matrix[i][0], i, 0);
        que.push(temp1);
    }
    for (int i = 0; i < k - 1; i++) {
        point min_point = que.top();
        que.pop();
        if (min_point.y < n - 1) {
            // next to the min, 1 then 5 then 9
            point temp2(matrix[min_point.x][min_point.y + 1], min_point.x, min_point.y + 1);
            que.push(temp2);
        }
    }
    return que.top().val;
}

int main() {
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    cout << kthSmallest(matrix, 8) << endl;
    return 0;
}