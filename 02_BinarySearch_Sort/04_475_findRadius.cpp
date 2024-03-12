#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 输入: houses = [1,2,3], heaters = [2]
// 输出: 1
// 解释: 仅在位置 2 上有一个供暖器。如果我们将加热半径设为 1，那么所有房屋就都能得到供暖。

int findRadius(vector<int>& houses, vector<int>& heaters) {
    // 所有房屋需要的供暖器的最小加热半径中的最大值即为可以覆盖所有房屋的最小加热半径。
    // sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    vector<int> res;
    for (auto house: houses) {
        if (house <= heaters[0] || house >= heaters.back()) {
            res.push_back(min(abs(house - heaters[0]), abs(heaters.back() - house)));
        } else {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            //cout << house << "," << it - heaters.begin() << endl;
            if (it != heaters.end()) {
                int index = it - heaters.begin();
                int temp1 = abs(house - it[0]);
                if (index > 0) {
                    int temp2 = abs(house - heaters[index - 1]);
                    res.push_back(min(temp1, temp2));
                }
                else res.push_back(temp1);
            }
        }
    }
    int ans = 0;
    for (auto r: res) {
        ans = max(ans, r);
    }
    return ans;
}

int main() {
    vector<int> houses = {1,5};
    vector<int> heaters = {2};
    cout << findRadius(houses, heaters) << endl;
}