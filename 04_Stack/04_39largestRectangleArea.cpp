#include <stack>
#include <vector>
#include <iostream>
using namespace std;

// 输入：heights = [2,1,5,6,2,3]
// 输出：10
// 解释：最大的矩形为图中红色区域，面积为 10  (5,6 这俩位置构成的)

// 6 7 6 8 6 2 最后的6位置可以准确的结算好
int largestRectangleArea(vector<int>& heights) {
    // 简单理解就是找到每个柱子左边第一个比自己矮的，和右边第一个比自己矮的，
    // 这两个矮的之间的距离都比这个柱子高或者相等，就能算出以这个柱子为高最大的面积。
    // 遍历每根柱子就可以了
    int res = 0, cur, left;
    stack<int> stk;
    for (int i = 0; i < heights.size(); i++) {
        while (!stk.empty() && heights[i] <= heights[stk.top()]) {
            cur = stk.top();
            stk.pop();
            left = stk.empty()? -1 : stk.top();
            res = max(res, (i - left - 1) * heights[cur]);
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        cur = stk.top();
        stk.pop();
        left = stk.empty()? -1 : stk.top();
        int temp = (heights.size() - left - 1) * heights[cur];
        res = max(res, temp);
    }
    return res;
}

int main() {

}