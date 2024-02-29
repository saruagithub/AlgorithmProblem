#include <stack>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/iIQa4I/description/
// 要求其对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。
// 输入: temperatures = [73,74,75,71,69,72,76,73]
// 输出: [1,1,4,2,1,1,0,0]

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> stk;
    vector<int> res(temperatures.size());
    for (int i = 0; i < temperatures.size(); i++) {
        // 不能单调递减了，出栈
        while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
            res[stk.top()] = i - stk.top();
            stk.pop();
        }
        // 相等也加入单调栈
        stk.push(i);
    }
    // if stk has data
    while (!stk.empty()) {
        res[stk.top()] = 0;
        stk.pop();
    }
    return res;
}

int main() {
    return 0;
}