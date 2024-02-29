#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 数轴x有两个点的序列A＝｛A1，A2，．．．Am｝和B＝｛B1，B2，．Bn｝，A和Bj均为正整数，A、B已经从小到大排好序，A、B均肯定不为空，给定一个距离R（正整数），列出同时满足如下条件的所有（Ai，Bj）数对

// 2、条件 1.Ai<=Bj
// 2．Ai，Bj距离小于等于R，但如果Ai找不到R范围内的Bj，则列出距它最近的1个Bj，当然此种情况仍然要满足1），但如果仍然找不到，就丢弃Ai
// 3、原型
// 车路协同Q场景，一条路上发生了有很多事件（A），要通过很多路测设备（B）广播给路上的车，需要给每个事件找到一个合适的路测设备去发送广播消息。

// 二、输入输出
// 按照人易读的格式输入一行数据，参见输入样例，其中“ABR＝｛，｝”中的每个字符都是关键分割符，输入中无空格，其他均为任意正整数，输入A和B已经排好序，A和B的大小不超过50，正整数范围不会超过65535。
// （Ai，Bj）数对序列，排列顺序满足序列中前面的Ax＜＝后面的Ay，前面的Bx＜＝后面的By，因为输入A和B已经排好序，所以实际上输出结果不用特意排序，排序不是考察点。

vector< vector<int> > meetScope(vector<int>&a, vector<int>& b, int R) {
    vector< vector<int> > res;
    for (int i = 0; i < a.size(); i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        if (it == b.end()) return res;
        int left_index = it - b.begin();
        for (int j = left_index; j < b.size(); j++) {
            if (b[j] - a[i] <= R) {
                cout << "(" << a[i] << "," << b[j] << ")" << endl;
                res.push_back({a[i], b[j]});
            } else {
                break;
            }
        }
    }
    return res;
}

int main() {
    vector<int> a = {1, 3, 5};
    vector<int> b = {2};
    int R = 2;
    meetScope(a, b, 2);
    return 0;
}