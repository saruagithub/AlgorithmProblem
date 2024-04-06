
// leecode 45
// 输入: nums = [2,3,1,1,4]
// 输出: 2
// 解释: 跳到最后一个位置的最小跳跃数是 2。
//      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
#include "../21_Huawei/21_header.h"

int jump(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    int res = 0;
    // [start, end) each get maxdis, judge maxdis > numslen
    // [0,1) -> [1,3)
    int start = 0, end = 1;
    while (end < nums.size()) {
        int maxdis = 0;
        for (int i = start; i < end; i++) {
            maxdis = max(maxdis, i + nums[i]);
        }
        start = end; // 下一回扫描范围
        end = maxdis + 1;
        res++;
    }
    
    return res;
}