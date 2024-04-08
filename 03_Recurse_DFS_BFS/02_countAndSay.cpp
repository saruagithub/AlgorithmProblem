//
//  02_ countAndSay.cpp
//  AlgorithmProblem
//
//  Created by wangxue on 2020/10/30.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

//leecode 38
//第一项是数字 1
//描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"
//描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"

string countAndSay(int n) {
    if(n == 1) return "1";

    string previous = countAndSay(n-1), result = ""; // 使用递归来一层一层往前推
    int count = 1; // count用来计数

    for(int i=0;i<previous.length();i++)
    {
        if(previous[i] == previous[i+1])
        {
            count ++; // 比如previous是111221时，111部分会让count=3，此时i在第三个1处
        }
        else
        {
            result += to_string(count) + previous[i]; // result会从空变成“31”（当i在第三个1处时）
            count = 1; // 由于i在第三个1处时，i+1处的值为2，1 != 2，所以count重新变成1
        }
    }

    return result;
}

/* 解法 遍历 */
void concat(string &res, char c, int cnt){
    res += to_string(cnt);
    res += c;
}
string des(string s) {
    string res;
    int cnt = 0;
    for(int i=0; i<s.size(); i++){
        if(cnt==0 || s[i]==s[i-1]){
            cnt++;
        } else {
            //拼接字符s[i-1] 和 count 到res里
            concat(res, s[i-1], cnt);
            cnt = 1;
        }
    }
    concat(res, s[s.size()-1], cnt);
    return res;
}
string countAndSay1(int n) {
    string ans = "1";
    for(int i = 2; i <= n; i++){
        ans = des(ans);
    }
    return ans;
}

void test_countAndSay(){
    string ans;
    ans = countAndSay(5);
    cout<<ans<<endl;
}
