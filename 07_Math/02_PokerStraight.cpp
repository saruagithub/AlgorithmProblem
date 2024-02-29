//
//  02_PokerStraight.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/6.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。ve
//如果我们能够知道 5 张扑克牌中的最大值 maxValuemaxValue 和最小值 minValueminValue ，那我们就知道，要使它为顺子需要 maxValue - minValue + 1 张牌。
//在查找 maxValuemaxValue 和 minValueminValue 过程中，跳过大小王 0 。
//如果 maxValue - minValue + 1 > 5，说明题目给的 5 张牌不足以构成顺子，返回 false .
//即使里面有大小王，也不够用来填补使它构成顺子。
//如果 maxValue - minValue + 1 <= 5，说明 5 张牌足以构成顺子，返回 true。大小王填补在合适位置即可。再定义一个标志数组判断是否有重复数字，发现重复数字直接返回 false 即可

bool isStraight(vector<int>& nums) {
    bool m[15];
    memset(m, 0, sizeof(m));
    int minValue = 14, maxValue = 0;
    for (int item : nums) {
        if (item == 0) {
            continue;
        }
        if (m[item]) {
            return false;
        }
        m[item] = true;
        minValue = min(minValue, item);
        maxValue = max(maxValue, item);
    }
    return maxValue - minValue + 1 <= 5;
}
