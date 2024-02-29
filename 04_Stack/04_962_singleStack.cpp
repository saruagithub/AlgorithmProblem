#include <stack>
#include <vector>
using namespace std;

int maxWidthRamp(vector<int>& nums) {
    // 递减的话进栈
    stack<int> stk;
    // nums[0] index 0 put into stk
    stk.push(0);
    for (int i = 1; i < nums.size(); i++) {
        if (nums[stk.top()] > nums[i]) {
            stk.push(i);
        }
    }
    // 从后往前算最长坡，不停更新
    int res = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
        // 可以组成坡
        while (!stk.empty() && nums[i] >= nums[stk.top()]) {
            res = max(res, i - stk.top());
            stk.pop();
        }
    }
    return res;
}