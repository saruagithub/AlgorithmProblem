//
//  01_stockProfit.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/6.
//

#include <iostream>
#include <vector>
using namespace std;
//如果能在遍历的过程中能够记录当前元素之前的最小值， 那么就可以优化掉一次循环。 从而将时间复杂度降为 O(n)
//题目要求是计算一次交易的最大利润， 如何获得最大的利润？， 就是要在最低点买入， 然后在最高点卖出。

int maxProfit(vector<int>& prices){
    if(prices.size() == 0)
        return 0;
    int minPrice = prices[0];
    int maxGap = 0;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]); // 更新最小值
        maxGap = max(maxGap, prices[i] - minPrice); // 更新最大值
    }
    return maxGap;
}
