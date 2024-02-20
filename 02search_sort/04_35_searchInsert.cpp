#include <iostream>
#include <vector>
using namespace std;

//leecode 35
int searchInsert(vector<int>& nums, int target) {
    size_t left = 0, right = nums.size() - 1, ans = nums.size();
    while (left <= right) {
        size_t mid = ((right - left) >> 1) + left;
        if (target <= nums[mid]) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return int(ans);
}
