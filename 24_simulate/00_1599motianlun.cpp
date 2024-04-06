#include <vector>
#include <algorithm>
using namespace std;

// leecode1599
// 你正在经营一座摩天轮，该摩天轮共有 4 个座舱 ，
// 每个座舱 最多可以容纳 4 位游客 。你可以 逆时针 轮转座舱，但每次轮转都需要支付一定的运行成本 runningCost 。
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        if (boardingCost * 4 < runningCost) return -1;
        int waitNum{}, turns = -1, maxProf{}, curProf{};
        for (int i = 0; i < customers.size() || waitNum; i++) {
            int curNum = waitNum + (i < customers.size() ? customers[i] : 0);
            curProf += min(curNum, 4) * boardingCost - runningCost;
            waitNum = max(0, curNum - 4);
            if (curProf > maxProf) {
                turns = i + 1;
                maxProf = curProf;
            }
        }
        return turns;
    }
};

int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
    if (boardingCost * 4 < runningCost) return -1;
    const int seat = 4;
    int leftcust = 0;
    int profit = 0;
    int maxprofit = 0;
    int times = 1;
    int res = 0;
    int lastboard = 0;
    int realboard = 0;
    for (int cust : customers) {
        if (cust + leftcust > seat) {
            realboard = seat;
            leftcust = cust + leftcust - seat;
        } else {
            realboard = cust + leftcust;
            leftcust = 0;
        }
        profit = (realboard + lastboard) * boardingCost - times * runningCost;
        if (profit > maxprofit) {
            maxprofit = profit;
            res = times;
        }
        //profit = max(profit, (realboard + lastboard) * boardingCost - times * runningCost);
        lastboard += realboard;
        times++;
    }
    while (leftcust > 0) {
        realboard = min(leftcust, seat);
        profit = (realboard + lastboard) * boardingCost - times * runningCost;
        if (profit > maxprofit) {
            maxprofit = profit;
            res = times;
        }
        //profit = max(profit, (realboard + lastboard) * boardingCost - times * runningCost);
        lastboard += realboard;
        leftcust -= seat;
        times++;
    }
    if (maxprofit <= 0) return -1;
    return res;
}