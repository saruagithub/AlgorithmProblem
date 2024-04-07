#include <vector>
using namespace std;

// leecode101 分割等和子集
// 给定一个非空的正整数数组 nums ，请判断能否将这些数字分成元素和相等的两部分。
bool canPartition(vector<int>& nums) {
    if (nums.size() < 2) return false;
    int allsum = 0, maxval = 0;
    for (auto ele : nums) {
        allsum += ele;
        maxval = max(maxval, ele);
    }
    if (allsum % 2 != 0 || maxval > (allsum / 2)) return false;
    int target = allsum / 2;
    // choose nums so sum = target
    // dp[i][j] : choose from [0 ~ i] , if sum == j, dp[i][j] = true
    
    // if nums[i] > j, dp[i][j] = dp[i-1][j]
    // else dp[i][j] = dp[i-1][j].  or dp[i][j] = dp[i-1][j - nums[i]]

    // init dp[i][0] = true;  dp[0][nums[0]] = true
    bool dp[nums.size()][target+1];
    memset(dp, false, sizeof(dp));
    for (int i = 0; i < nums.size(); i++) {
        dp[i][0] = true;
        if(nums[0] == nums[i]) dp[0][nums[i]] = true;
    }
    //dp[0][nums[0]] = true;
    for (int i = 1; i < nums.size(); i++) {
        // choose i or not
        for (int j = 1; j <= target; j++) {
            if (j < nums[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
        }
    }
    return dp[nums.size() - 1][target];
}


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 等和需要以下条件
        // 1. 数组内所有元素的和必须是偶数
        // 2. 数组内某些元素的总和必须是这个偶数的一半
        int m = nums.size();
        int sum = 0;
        for (int i = 0; i < m; i++)
            sum += nums[i];
        if (sum & 1) return false;
        sum >>= 1;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 0; i < m; i++) {
            for (int j = sum - nums[i]; j >= 0; j--) {
                if (dp[j]) dp[j + nums[i]] = true;
            }
        }
        return dp[sum];
    }
};