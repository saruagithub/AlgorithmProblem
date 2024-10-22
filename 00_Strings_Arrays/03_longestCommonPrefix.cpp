//
//  03_longestCommonPrefix.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/9/23.
//

#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs){
    if (strs.size() == 0) {
        return "";
    }
    string prefix = strs[0];
    for(int i=1; i<strs.size(); i++){
        //如果不含有prefix，则将prefix长度减1
        while (strs[i].find(prefix) != 0) {
            if (prefix == "") {
                return "";
            }
            prefix = prefix.substr(0,prefix.length() - 1);
        }
    }
    return prefix;
}

string longestCommonPrefix1(vector<string>& strs) {
    //两个公共字符串的前缀与第三个比,再比直到最后一个，如果中间有空了就不用继续算了
    if(strs.size() == 0) return "";
    string ans = strs[0];
    for(int i = 1; i < strs.size(); i++){ //第i字符串和t比较
        string t = ans;
        ans = "";
        for(int j=0; j<t.size() && j<strs[i].size(); j++){
            if(t[j] == strs[i][j]) ans += t[j];
            else break;
        }
        if(ans == "") break;
    }
    return ans;
}
