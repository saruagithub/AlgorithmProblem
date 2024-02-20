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
// eg, {4,5,6,7,0,1,2} target = 0; res = 4
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() -1, mid = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (target == nums[mid]) return mid;
        else if (nums[mid] >= nums[0]) {
            if (target >= nums[0] && nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (target <= nums.back() && target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;
}


int main() {
    vector<int> nums = {2,2,4,5,1,2,2,2}; // res = 1
    cout << findMin(nums) << endl;
}