#include <vector>
#include <algorithm>

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    // 根据每只蚂蚁的初始位置和移动方向得到最后一只蚂蚁到达木板边界的时刻。
    int res = 0;
    for (int l : left) {
        res = max(res, l);
    }
    for (int r : right) {
        res = max(res, n - r);
    }
    return res;
}