#include <vector>
#include <unordered_map>
using namespace std;

// 给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
// https://leetcode.cn/problems/A1NYOS/description/

int findMaxLength(vector<int>& nums) {
    int counter = 0, res = 0;
    // 哈希表存储的是 counter 的每个取值第一次出现的下标
    unordered_map<int, int> mp;
    mp[counter] = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) counter--;
        else counter++;
        if (mp.count(counter)) {
            int prevIdx = mp[counter];
            res = max(res, i - prevIdx);
        } else {
            mp[counter] = i;
        }
    }
    return res;
}