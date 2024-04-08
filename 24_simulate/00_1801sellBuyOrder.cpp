#include <vector>
#include <queue>
#include <algorithm>

constexpr int MOD = 1e9 + 7;
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>> buy;
        priority_queue sell{ greater<>{}, vector<pair<int, int>>{} };

        return accumulate(orders.begin(), orders.end(), 0, [&](int a, auto& v) {
            auto func = [&](auto& q1, auto& q2, auto&& op) {
                while (v[1] && !q1.empty() && op(q1.top().first, v[0])) {
                    auto [price, cnt] = q1.top();
                    q1.pop();
                    auto tmp = min(cnt, v[1]);
                    v[1] -= tmp;
                    cnt -= tmp;
                    a = (a + MOD - tmp) % MOD;
                    if (cnt) q1.emplace(price, cnt);
                }
                if (v[1]) q2.emplace(v[0], v[1]);
                return (a + v[1]) % MOD;
            };
            return v[2] ? func(buy, sell, greater_equal<>{}) : func(sell, buy, less_equal<>{});
        });
    }
};

int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    // 寻找已有的积压订单时，需要寻找价格最高的采购订单或者价格最低的销售订单 priority_queue
    int finalmod = 1000000007;

    // price and mount
    priority_queue<pair<int, int>> buyOrders;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sellOrders;

    for (vector<int>& order : orders) {
        int price = order[0], amout = order[1], orderType = order[2];
        if (orderType == 0) {
            while (amout > 0 && !sellOrders.empty() && sellOrders.top().first <= price) {
                auto sell = sellOrders.top();
                sellOrders.pop();
                int sellamount = min(amout, sell.second);
                amout -= sellamount;
                sell.second -= sellamount;
                if (sell.second > 0) sellOrders.push(sell);
            }
            if (amout > 0) buyOrders.push(make_pair(price, amout));
        } else {
            while (amout > 0 && !buyOrders.empty() && buyOrders.top().first >= price) {
                auto buy = buyOrders.top();
                buyOrders.pop();
                int buyamount = min(amout, buy.second);
                amout -= buyamount;
                buy.second -= buyamount;
                if (buy.second > 0) buyOrders.push(buy);
            }
            if (amout > 0) sellOrders.push(make_pair(price, amout));                
        }
    }
    int res = 0;
    while (!sellOrders.empty()) {
        res = (res + sellOrders.top().second) % finalmod;
        sellOrders.pop();
    }
    while (!buyOrders.empty()) {
        res = (res + buyOrders.top().second) % finalmod;
        buyOrders.pop();
    }
    return res;
}