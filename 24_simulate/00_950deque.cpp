#include <deque>
#include <vector>
using namespace std;

// leecode950
// 输入：[17,13,11,2,3,5,7]
// 输出：[2,13,3,11,5,17,7]
// 解释：
// 我们得到的牌组顺序为 [17,13,11,2,3,5,7]（这个顺序不重要），然后将其重新排序。
// 重新排序后，牌组以 [2,13,3,11,5,17,7] 开始，其中 2 位于牌组的顶部。
// 我们显示 2，然后将 13 移到底部。牌组现在是 [3,11,5,17,7,13]。
// 我们显示 3，并将 11 移到底部。牌组现在是 [5,17,7,13,11]。
// 我们显示 5，然后将 17 移到底部。牌组现在是 [7,13,11,17]。
// 我们显示 7，并将 13 移到底部。牌组现在是 [11,17,13]。
// 我们显示 11，然后将 17 移到底部。牌组现在是 [13,17]。
// 我们展示 13，然后将 17 移到底部。牌组现在是 [17]。
// 我们显示 17。
// 由于所有卡片都是按递增顺序排列显示的，所以答案是正确的

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    int n = deck.size();
    deque<int> dque;
    // 逆向思维
    for (int i = n - 1; i >= 0; i--) {
        if (!dque.empty()) {
            dque.push_front(dque.back());
            dque.pop_back();
        }
        dque.push_front(deck[i]);
    }
    vector<int> res(dque.begin(), dque.end());
    return res;
}