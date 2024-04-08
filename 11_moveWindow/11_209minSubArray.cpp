#include "../21_Huawei/21_header.h"

// leecode209
// 找出该数组中满足其总和大于等于 target 的长度最小的 连续
// 子数组[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

// 输入：target = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的子数组。

int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0;
    int l = 0, r = 0, reslen = INT_MAX;
    while (r < nums.size()) {
        if (nums[r] > target) return 1;
        while (r < nums.size() && sum < target) {
            sum += nums[r];
            r++;
        }
        //cout << "1l = " << l << "r = " << r << " " << sum << endl;
        reslen = min(reslen, r - l);
        while (l < nums.size() && sum >= target) {
            sum -= nums[l];
            l++;
        }
        //cout << "2l = " << l << "r = " << r << " " << sum << endl;
        if (l > 0 && sum + nums[l-1] >= target) reslen = min(reslen, r - l +1);
    }
    if (l > 0 && reslen != INT_MAX) return reslen;
    else return 0;
}