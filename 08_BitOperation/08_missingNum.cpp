#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int missingNumber(vector<int>& nums) {
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++) {
        set.insert(nums[i]);
    }
    int missing_res = -1;
    for (int i = 0; i <= nums.size(); i++) {
        if (!set.count(i)) {
            missing_res = i;
            break;
        }
    }
    return missing_res;
}

//按位异或运算满足交换律和结合律
int missingNumber1(vector<int>& nums) {
    int res = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        res ^= nums[i];
        res ^= i;
    }
    return res ^ n;
}

// leecode 136 只出现1次的数字
int singleNumber(vector<int>& nums) {
    int eor = 0;
    for (int num: nums) {
        eor ^= num;
    }
    return eor;
}

int main() {
    vector<int> nums = {0, 1, 2};
    cout << missingNumber1(nums);
    return 0;
}