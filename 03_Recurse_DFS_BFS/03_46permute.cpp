#include "../21_Huawei/21_header.h"

// leecode46
// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 建议先画树形图 ，画图能帮助我们想清楚递归结构，想清楚如何剪枝
vector<vector<int>> res;
void dfs(vector<int>& tmp, vector<bool>& flag, vector<int>& nums) {
    if (tmp.size() == nums.size()) {
        res.push_back(tmp);
        return;
    }
    // choose from the left num
    for (int i = 0; i < nums.size(); i++) {
        // move duplicated leecode47
        if (flag[i] || (i > 0 && nums[i] == nums[i-1] && !flag[i-1])) {
            continue;
        }
        flag[i] = true;
        tmp.push_back(nums[i]);
        dfs(tmp, flag, nums);
        flag[i] = false;
        tmp.pop_back();  
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<int> tmp;
    vector<bool> flag(nums.size(), false);
    // leecode47
    sort(nums.begin(), nums.end());
    dfs(tmp, flag, nums);
    return res;
}