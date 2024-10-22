#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int pairs_sum(vector<int>& nums, int k) {
    int res = 0;
    unordered_map<int, int> mmp; // val and times
    for (int i = 0; i < nums.size(); i++) {
        if (mmp.find(k - nums[i]) != mmp.end() && mmp[k - nums[i]] > 0) {
            res++;
            mmp[k - nums[i]]--;
        } else {
            mmp[nums[i]]++; // save the num
        }
    }
    return res;
}

int main() {
    vector<int> nums = {0,0,0,0};
    int k = 1;
    cout << pairs_sum(nums, k);
    return 0;
}