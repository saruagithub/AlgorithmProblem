#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// 示例 1：
// 输入：paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
// 输出："Sao Paulo" 
// 解释：从 "London" 出发，最后抵达终点站 "Sao Paulo" 。本次旅行的路线是 "London" -> "New York" -> "Lima" -> "Sao Paulo" 

string destCity(vector<vector<string>>& paths) {
    unordered_set<string> allA;
    for (auto &path :  paths) {
        allA.insert(path[0]);
    }
    for (auto &path: paths) {
        if (!allA.count(path[1])) return path[1];
    }
    return "";
}