
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>  // double queue -> <-
#include <stack>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

int test(int N, int per, vector<vector<int>> nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    res.push_back(nums[0]);
    // 必须覆盖1 - N个题目
    if (res.back()[0] != 1) {
        return -1;
    }
    for (int i = 1; i < per; i++) {
        if (res.back()[1] == N) {
            return res.size();
        }
        if (nums[i][0] > res.back()[1] + 1) {
            return -1;
        }
        if (nums[i][0] == res.back()[0]) {
            res.back()[1] = nums[i][1];
            continue;
        }
        int j = i + 1;
        for (; j < per; j++) {
            if (nums[j][0] > res.back()[1] + 1) break;
        }
        res.push_back(nums[j - 1]);
        i = j - 1;
    }
    int ans = res.back()[1] == N ? res.size() : -1;
    return ans;
}


int main()
{
    // please define the C input here. FOR EXAMPLE: int n; scanf("%d",&n);
    // please finish the FUNCTION body here.
    // please define the C output here. FOR EXAMPLE: printf("%d",a);
    int N;
    cin >> N;
    int per;
    cin >> per;
    int i = 0;
    vector<vector<int>> nums;
    while (i < per) {
        int a, b;
        cin >> a >> b;
        nums.push_back({a, b});
        i++;
    }
    cout << test(N, per, nums) << endl;
    // sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b){
    //     return a[0] < b[0];
    // });
    //for(auto ele : nums) cout << ele[0] << " " << ele[1] << endl;

    // sort(nums.begin(), nums.end());
    // //for(auto ele : nums) cout << ele[0] << " " << ele[1] << endl;

    // vector<vector<int>> res;
    // res.push_back(nums[0]);
    // if (per == 1) {
    //     if (nums[0][0] == 1 && nums[0][1] == N) {
    //         cout << 1 << endl;
    //     } else {
    //         cout << -1 << endl;
    //     }
    //     return 0;
    // }

    // for (int i = 1; i < nums.size(); i++) {
    //     if (nums[i][0] > res.back()[1] + 1) {
    //         cout << -1 << endl;
    //         return 0;
    //     } else if (nums[i][0] == res.back()[0]) {
    //         res.back()[1] = res.back()[1];
    //         if (res.back()[1] == N) {
    //             cout << res.size() << endl;
    //             return 0;
    //         }
    //     } else {
    //         int j = i;
    //         for (; j < nums.size(); j++) {
    //             if (nums[j][0] > res.back()[1] + 1) {
    //                 break;
    //             }
    //         }
    //         int left = nums[j - 1][0];
    //         int right = nums[j - 1][1];
    //         //cout << "i j l r " << i << " , " << j << " " << left << " " << right << endl;
    //         res.push_back({left, right});
    //         i = j - 1;
    //     }
    // }
    // if (res.back()[1] != N) cout << -1 << endl;
    // else cout << res.size() << endl;
    // for (auto e : res) cout << e[0] << "," << e[1] << endl;
    return 0;
}
