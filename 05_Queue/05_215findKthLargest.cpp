#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> que;
    for (int ele : nums) {
        que.push(ele);
    }
    int res = 0;
    int i = 0;
    while (i < k) {
        res = que.top();
        que.pop();
        i++;
    }
    return res;
}