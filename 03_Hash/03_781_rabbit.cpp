#include "../21_Huawei/21_header.h"

// 提问其中若干只兔子 "还有多少只兔子与你（指被提问的兔子）颜色相同?" 
// 将答案收集到一个整数数组 answers 中，其中 answers[i] 是第 i 只兔子的回答。
// 给你数组 answers ，返回森林中兔子的最少数量。

// 输入：answers = [1,1,2]
// 输出：5

int numRabbits(vector<int>& answers) {
    unordered_map<int,int> map;
    for(auto ans: answers) {
        if(map.count(ans) == 0) {
            map[ans] = 1;
        } else {
            map[ans] += 1;
        }
    }
    // calculate res
    int res = 0;
    for(auto [key,val]: map) {
        if (key == 0) {
            // 唯一的颜色兔子
            res += val;
            continue;
        }
        if(val <= key + 1) {
            res += key + 1;
        } else {
            int cnt = val%(key+1)==0 ? val / (key+1) : val / (key + 1) + 1;
            res += (key+1) * cnt;
        }
    }
    return res;
}