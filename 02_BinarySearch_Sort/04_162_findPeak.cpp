// 峰值元素是指其值严格大于左右相邻值的元素。

// 给你一个整数数组 `nums`，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 **任何一个峰值** 所在位置即可。

// 你可以假设 `nums[-1] = nums[n] = -∞` 。

// 你必须实现时间复杂度为 `O(log n)` **的算法来解决此问题。这也可以二分

// eg nums = [1,2,3,1] output = 2, 因为3是峰值，返回索引2
// eg nums = [1,2,1,3,5,6,4]  output = 1 or 5, 峰值可以是2也可以是6
#include "02_header.h"
using namespace std;

int findPeakElement(vector<int>& nums) {
    if (nums.size() == 1 || nums[1] < nums[0]) return 0;
    int n = nums.size() - 1;
    if (nums[n] > nums[n-1]) return n;
    int l = 1, r = n - 1, m = 0;
    while(l <= r) {
        m = l + ((r - l) >> 2);
        if (nums[m - 1] > nums[m]) r = m -1;
        else if (nums[m] < nums[m + 1]) l = m + 1;
        else return m;
    }
    return m;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << findPeakElement(nums) << endl;
}