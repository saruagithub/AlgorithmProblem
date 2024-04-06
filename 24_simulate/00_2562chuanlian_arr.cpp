#include <vector>

//2562. 找出数组的串联值
long long findTheArrayConcVal(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int l = 0, r = nums.size() - 1;
    long long res = 0;
    while (l < r) {
        string tmp = to_string(nums[l]) + to_string(nums[r]);
        res += stoi(tmp);
        l++;
        r--;
    }
    if (l == r) res += nums[l];
    return res;
}