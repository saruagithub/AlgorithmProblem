#include <string>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

double minimumAverage(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    double res = numeric_limits<double>::max();
    for (int i = 0; i < n / 2; i++) {
        res = min(res, (nums[i] + nums[n - 1 - i]) / 2.0);
    }
    return res;
}

int limits_num() {
    std::cout << "type\t│ lowest()\t│ min()\t\t│ max()\n"
              << "bool\t│ "
              << std::numeric_limits<bool>::lowest() << "\t\t│ "
              << std::numeric_limits<bool>::min() << "\t\t│ "
              << std::numeric_limits<bool>::max() << '\n'
              << "uchar\t│ "
              << +std::numeric_limits<unsigned char>::lowest() << "\t\t│ "
              << +std::numeric_limits<unsigned char>::min() << "\t\t│ "
              << +std::numeric_limits<unsigned char>::max() << '\n'
              << "int\t│ "
              << std::numeric_limits<int>::lowest() << "\t│ "
              << std::numeric_limits<int>::min() << "\t│ "
              << std::numeric_limits<int>::max() << '\n'
              << "float\t│ "
              << std::numeric_limits<float>::lowest() << "\t│ "
              << std::numeric_limits<float>::min() << "\t│ "
              << std::numeric_limits<float>::max() << '\n'
              << "double\t│ "
              << std::numeric_limits<double>::lowest() << "\t│ "
              << std::numeric_limits<double>::min() << "\t│ "
              << std::numeric_limits<double>::max() << '\n';
}

int main() {
    vector<int> num = {0, 1, 2, 3, 4};
    cout << minimumAverage(num);
    limits_num();
    return 0;
}

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/minimum-average-of-smallest-and-largest-elements/solutions/2943777/zui-xiao-yuan-su-he-zui-da-yuan-su-de-zu-2kab/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。