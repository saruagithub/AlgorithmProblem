#include <iostream>
#include <vector>
using namespace std;

// leecode 54 {2,2,4,5,1,2,2,2}; // res = 1
int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] > nums[r]) {
            l = mid + 1;
        } else if (nums[mid] < nums[r]) {
            // do not miss the min value
            r = mid;
        } else {
            r--;
        }
    }
    return nums[l];
}

// leecode 33 搜索旋转排序数字里的target的index
// 整数数组 nums 按升序排列，数组中的值 互不相同 。

// 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，
// 使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
// （下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
// 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
// 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

// eg, {4,5,6,7,0,1,2} target = 0; res = 4
int searchRotate(vector<int>& nums, int target) {
    int l = 0, r = nums.size() -1, mid = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (target == nums[mid]) return mid;
        else if (nums[mid] == nums[r]) {
            r = r - 1;
        }
        else if (nums[mid] > nums[r]) {
            if (target >= nums[l] && nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (target <= nums[r] && target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;
}


int main() {
    vector<int> nums = {2,2,4,5,1,2,2,2}; // res = 1 (min value)
    cout << findMin(nums) << endl;
    vector<int> nums1 = {4,5,6,7,0,1,2}; // res = 6 (index)
    cout << searchRotate(nums1, 2) << endl;
}