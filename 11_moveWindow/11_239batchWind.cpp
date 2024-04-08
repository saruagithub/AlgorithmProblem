#include "../21_Huawei/21_header.h"

//leecode239
// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7


vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
    if (k == 1) return nums;
    vector<int> res(nums.size() - k + 1);
    int l = 0, r = l + k; //[l,r)
    int max = 0, max_index = 0;

    // window move
    while (r <= nums.size()) {
        if (l < max_index) {
            if (nums[r - 1] < max) {
                //cout << "1l maxIdx r" << l << " " << max_index << " " << r << " "<<endl;
                res[l] = max;
            }
            else {
                max = nums[r - 1];
                max_index = r - 1;
                //cout << "2l maxIdx r" << l << " " << max_index << " " << r << " "<<endl;
                res[l] = max;
            }
        } else {
            max = nums[l];
            for (int i = l; i < r; i++) {
                if (nums[i] > max) {
                    max = nums[i];
                    max_index = i;
                }
            }
            //cout << "3l maxIdx r" << l << " " << max_index << " " << r << " "<<endl;
            res[l] = max;
        }
        l++;
        r++;
    }
    return res;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < k; i++) {
        q.push(make_pair(nums[i], i));
    }
    // 第一个最大值
    vector<int> res = {q.top().first};
    for (int i = k; i < n; i++) {
        // 放入末尾新入元素
        q.push(make_pair(nums[i],i));
        while (q.top().second <= i - k) {
            // 去除不在滑动窗范围的最大值，但其实que里的元素多于k，不影响结果
            q.pop();
        }
        res.push_back(q.top().first);
    }
    return res;
}