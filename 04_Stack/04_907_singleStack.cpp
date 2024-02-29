#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// leecode 907 给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。
// 输入：arr = [3,1,2,4]
// 输出：17
// 解释：
// 子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。 
// 最小值为 3，1，2，4，1，1，2，1，1，1，和为 17

int sumSubarrayMins(vector<int>& arr) {
    long res = 0;
    int cur_index, left_index;
    stack<int> stk;
    for (int i = 0; i < arr.size(); i++) {
        while (!stk.empty() && arr[i] <= arr[stk.top()]) {
            cur_index = stk.top();
            stk.pop();
            left_index = stk.empty()? -1 : stk.top();
            // 以arr[cur_index]为min * 左右两边组合起来的数组多少种
            res =  (res + long(arr[cur_index] * (cur_index - left_index) * (i - cur_index))) % 1000000007;
        }
        stk.push(i);
    }
    // stk still has data
    while(!stk.empty()) {
        cur_index = stk.top();
        stk.pop();
        left_index = stk.empty()? -1 : stk.top();
        res = (res + long(arr[cur_index] * (cur_index - left_index) * (arr.size() - cur_index))) % 1000000007;
    }
    return (int)res;
}