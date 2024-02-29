#include <vector>
#include <stack>
#include <iostream>
using namespace std;

static int MAXN = 1000000;
static vector<int> arr(MAXN);
static stack<int> stk;
// static vector<vector<int>> vec(MAXN, vector<int>(2,0)); // maxn * 2 , ele = 0
static int res[MAXN][2];
static int n;

// 求arr[i] 左边右边第一个小的数，所在的index
void leftRightMin() {
    int res_index;
    for(int i = 0; i < n; i++) {
        while (!stk.empty() && arr[i] <= arr[stk.top()]) {
            res_index = stk.top();
            stk.pop();
            int left = stk.empty()? -1 : stk.top();
            // int right = i;
            res[res_index][0] = left;
            res[res_index][1] = i;
        }
        // 严格大于才入栈 (stk.empty() || arr[i] > arr[stk.top()])
        stk.push(i);
    }
    // 遍历结束但stak里还有数据
    while (!stk.empty()) {
        res_index = stk.top();
        stk.pop();
        res[res_index][0] = stk.empty()? -1 : stk.top();
        res[res_index][1] = -1; // 右边没有更小的数字了
    }
    // 相等的话，右边的右边，特殊处理
    for (int i = n - 2; i >=0; i--) {
        if (res[i][1] != -1 && arr[res[i][1]] == arr[i]) {
            res[i][1] = res[res[i][1]][1];
        }
    }
}

int main() {
    int temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr[i] = temp;
    }
    leftRightMin();
    for (int i = 0; i < n; i++) {
        cout << res[i][0] << "," << res[i][1] << endl;
    }
    return 0;
}

// 单调栈
// 维持求解答案的可能性
// 当某个对象进入单调栈时候，从栈顶淘汰，并结算当前对象参与的可能答案 （弹出之后，不参与后续答案求解了）